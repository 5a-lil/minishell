/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_cmd_process.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khadj-me <khalilhadjmes1@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 12:14:00 by dangtran          #+#    #+#             */
/*   Updated: 2025/03/22 07:38:59 by khadj-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	close_files(int fds[2])
{
	if (fds[0] != -1)
		close(fds[0]);
	if (fds[1] != -1)
		close(fds[1]);
}

static void	child_process(char *cmd, t_data *data, t_list *curr, int *temp_fds)
{
	signal(SIGINT, SIG_DFL);
	redir(curr, data->stds, data);
	if (temp_fds[0] == -1 || temp_fds[1] == -1)
	{
		data->exit_code = 1;
		data->end_tty = 1;
	}
	if (data->end_tty != 1)
		exec_cmd(cmd, data->env_vars, data);
	else
		free(cmd);
}

static void	parent_process(char *cmd, t_list *cmd_l, t_data *data,
		int temp_fds[2])
{
	signal(SIGINT, &ctrl_c_no_display);
	signal(SIGQUIT, SIG_IGN);
	if (is_heredoc(cmd_l) == TRUE)
		wait(NULL);
	free(cmd);
	ft_lstclear(&cmd_l, &free);
	close(INFILE);
	close_files(temp_fds);
	while (waitpid(-1, &data->child_exit_code, 0) > 0)
		continue ;
	signal(SIGINT, &ctrl_c_display);
	if (WIFSIGNALED(data->child_exit_code))
	{
		if (WTERMSIG(data->child_exit_code) != SIGPIPE)
			data->exit_code = 128 + WTERMSIG(data->child_exit_code);
		if (WTERMSIG(data->child_exit_code) == SIGQUIT)
			printf("\n");
	}
	else
		data->exit_code = WEXITSTATUS(data->child_exit_code);
	g_sig = 0;
}

void	last_cmd_child_process(char *cmd, t_data *data)
{
	t_list	*cmd_l;
	t_list	*curr;
	int		id;
	int		temp_fds[2];

	temp_fds[0] = dup(0);
	temp_fds[1] = dup(1);
	cmd_l = init_prompt_list(cmd);
	if (!cmd_l)
		return (close_files(temp_fds));
	curr = cmd_l;
	signal(SIGQUIT, SIG_DFL);
	id = fork();
	if (id == -1)
		error_handler("fork failed");
	if (id == 0)
	{
		close_files(temp_fds);
		child_process(cmd, data, curr, data->stds);
	}
	else
		parent_process(cmd, cmd_l, data, temp_fds);
}
