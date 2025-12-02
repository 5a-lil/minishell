/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khadj-me <khalilhadjmes1@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 11:34:09 by khadj-me          #+#    #+#             */
/*   Updated: 2025/03/22 07:52:18 by khadj-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_heredoc(t_list *cmd_l)
{
	t_list	*curr;

	curr = cmd_l;
	while (curr)
	{
		if (((char *)curr->content)[0] == '<'
			&& ft_strlen((char *)curr->content) == 2)
			return (TRUE);
		curr = curr->next;
	}
	return (FALSE);
}

static void	child_process_fork_redir(t_list *curr, int *pipe_fd, t_data *data)
{
	redir(curr, pipe_fd, data);
	if (pipe_fd[0] == -1 || pipe_fd[1] == -1)
		return ;
	dup2(pipe_fd[OUTFILE], 1);
}

static void	child_process_fork(char *cmd, t_data *data, t_list *curr,
		int *pipe_fd)
{
	child_process_fork_redir(curr, pipe_fd, data);
	if (pipe_fd[0] == -1 || pipe_fd[1] == -1)
	{
		data->exit_code = 1;
		data->end_tty = 1;
	}
	close_files(pipe_fd);
	if (data->end_tty != 1)
		exec_cmd(cmd, data->env_vars, data);
	else
		free(cmd);
}

static void	parent_process_fork(int *pipe_fd)
{
	dup2(pipe_fd[INFILE], INFILE);
	close_files(pipe_fd);
}

void	fork_child_process(char *cmd, t_data *data)
{
	t_list	*cmd_l;
	t_list	*curr;
	int		id;
	int		pipe_fd[2];

	cmd_l = init_prompt_list(cmd);
	curr = cmd_l;
	if (!cmd_l)
		exit(errno);
	if (pipe(pipe_fd) == -1)
		error_handler(NULL);
	signal(SIGQUIT, SIG_DFL);
	id = fork();
	if (id == -1)
		error_handler(NULL);
	if (id == 0)
		child_process_fork(cmd, data, curr, pipe_fd);
	else
	{
		free(cmd);
		if (is_heredoc(cmd_l) == TRUE)
			wait(NULL);
		ft_lstclear(&cmd_l, &free);
		parent_process_fork(pipe_fd);
	}
}
