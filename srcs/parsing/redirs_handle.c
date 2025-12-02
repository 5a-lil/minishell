/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirs_handle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khadj-me <khalilhadjmes1@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 12:19:45 by dangtran          #+#    #+#             */
/*   Updated: 2025/03/22 07:54:56 by khadj-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_heredoc_input(t_data *data, char *limiter, int fd)
{
	char	*prompt;

	signal(SIGINT, ctrl_c_heredoc);
	rl_clear_history();
	prompt = readline("> ");
	if (g_sig == 130)
		return (data->end_tty = 1, data->exit_code = 130, free(prompt));
	while (prompt != NULL)
	{
		if (ft_strcmp(prompt, limiter) == 0)
			break ;
		write(fd, prompt, ft_strlen(prompt));
		write(fd, "\n", 1);
		free(prompt);
		prompt = readline("> ");
		if (g_sig == 130)
			return (data->end_tty = 1, data->exit_code = 130, free(prompt));
	}
	free(prompt);
}

void	heredoc(t_data *data, char *limiter)
{
	int	fd;

	g_sig = 0;
	printf("LIMITER : %s\n", limiter);
	fd = open(".heredoc.tmp", O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (fd < 0)
		return ;
	handle_heredoc_input(data, limiter, fd);
	close(fd);
	if (g_sig != 130)
	{
		fd = open(".heredoc.tmp", O_RDONLY, 0644);
		if (fd < 0)
			return ;
		dup2(fd, INFILE);
		close(fd);
	}
}

void	handle_output_redir(t_list **curr, int *temp_fds, int append,
		int (*f)(char *, int))
{
	*curr = (*curr)->next;
	if (curr && ft_strcmp((char *)(*curr)->content, "/dev/stdout") != 0)
	{
		close(temp_fds[OUTFILE]);
		if (append)
			temp_fds[OUTFILE] = f((char *)(*curr)->content, OUTFILE_APPEND);
		else
			temp_fds[OUTFILE] = f((char *)(*curr)->content, OUTFILE);
		if (temp_fds[OUTFILE] != -1)
			dup2(temp_fds[OUTFILE], OUTFILE);
	}
}

void	handle_input_redir(t_list **curr, int *temp_fds, int (*f)(char *, int))
{
	*curr = (*curr)->next;
	if (ft_strcmp((char *)(*curr)->content, "/dev/stdin") != 0)
	{
		close(temp_fds[INFILE]);
		temp_fds[INFILE] = f((char *)(*curr)->content, INFILE);
		if (temp_fds[INFILE] != -1)
			dup2(temp_fds[INFILE], INFILE);
	}
}
