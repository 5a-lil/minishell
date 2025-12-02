/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khadj-me <khalilhadjmes1@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 11:16:50 by dangtran          #+#    #+#             */
/*   Updated: 2025/03/22 07:51:54 by khadj-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	handle_single_command(t_list *list, t_list *env_vars, t_data *data,
		int *std_copy)
{
	int		stdout_copy;
	char	*temp_cmd;

	stdout_copy = dup(OUTFILE);
	temp_cmd = ft_strdup((char *)list->content);
	if (!temp_cmd)
		return (close(stdout_copy), 1);
	list = init_prompt_list((char *)list->content);
	if (!list)
		return (close(stdout_copy), free(temp_cmd), 1);
	redir(list, std_copy, data);
	if (std_copy[0] == -1 || std_copy[1] == -1)
		return (close(stdout_copy), free(temp_cmd), data->exit_code = 1, 1);
	exec_builtins(temp_cmd, env_vars, data);
	g_sig = 0;
	return (dup2(stdout_copy, OUTFILE), close(stdout_copy), 0);
}

static void	handle_multiple_commands(t_list *list, t_data *data)
{
	t_list	*curr;

	curr = list;
	while (curr != NULL && data->end_tty != 1)
	{
		if (curr->next == NULL)
		{
			last_cmd_child_process(ft_strdup((char *)curr->content), data);
			dup2(data->stdin_copy, INFILE);
		}
		else
		{
			fork_child_process(ft_strdup((char *)curr->content), data);
		}
		curr = curr->next;
	}
}

void	check_list(t_list *list, t_list *env_vars, t_data *data)
{
	int	std_copy[2];

	if (!list)
		return ;
	std_copy[0] = dup(INFILE);
	std_copy[1] = dup(OUTFILE);
	if (list->next == NULL)
	{
		if (is_builtin((char *)list->content) == 1)
		{
			handle_single_command(list, env_vars, data, std_copy);
			dup2(data->stdin_copy, INFILE);
			close_files(std_copy);
			return ;
		}
	}
	close_files(std_copy);
	handle_multiple_commands(list, data);
}
