/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khadj-me <khalilhadjmes1@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 11:40:04 by khadj-me          #+#    #+#             */
/*   Updated: 2025/03/21 14:22:48 by khadj-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	handle_execve_error(char **full_cmd, char *path, t_data *data)
{
	wait(NULL);
	ft_putstr_fd(full_cmd[0], 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd("command not found", 2);
	free(path);
	free_char_char(full_cmd);
	data->exit_code = 127;
	data->end_tty = 1;
}

static void	execute_command(char **full_cmd, t_data *data)
{
	char	*path;

	close_files(data->stds);
	close(data->stdin_copy);
	data->stdin_copy = -1;
	data->stds[0] = -1;
	data->stds[1] = -1;
	path = find_valid_path(data->env_vars, full_cmd);
	if (execve(path, full_cmd, data->envp) == -1)
		handle_execve_error(full_cmd, path, data);
}

void	exec_cmd(char *cmd, t_list *env_vars, t_data *data)
{
	t_list	*cmd_l;
	char	**full_cmd;

	cmd_l = init_without_redir_list(cmd);
	full_cmd = list_to_table(cmd_l);
	if (full_cmd == NULL || full_cmd[0] == NULL)
	{
		ft_lstclear(&cmd_l, &free);
		free_char_char(full_cmd);
		free(cmd);
		data->end_tty = 1;
	}
	else if (is_builtin(cmd) == 1)
	{
		ft_lstclear(&cmd_l, &free);
		free_char_char(full_cmd);
		exec_builtins(cmd, env_vars, data);
		data->end_tty = 1;
	}
	else
	{
		ft_lstclear(&cmd_l, &free);
		execute_command(full_cmd, data);
		free(cmd);
	}
}
