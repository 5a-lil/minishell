/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_builtins.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khadj-me <khalilhadjmes1@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 11:33:37 by khadj-me          #+#    #+#             */
/*   Updated: 2025/03/21 14:09:43 by khadj-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	openf_read(char *file)
{
	int	fd;

	fd = open(file, O_RDWR, 0644);
	if (fd == -1)
		perror(file);
	return (fd);
}

static int	openf_append(char *file)
{
	int	fd;

	fd = open(file, O_RDWR | O_APPEND | O_CREAT, 0644);
	if (fd == -1)
		perror(file);
	return (fd);
}

static int	openf_trunc(char *file)
{
	int	fd;

	fd = open(file, O_RDWR | O_TRUNC | O_CREAT, 0644);
	if (fd == -1)
		perror(file);
	return (fd);
}

int	openf_builtins(char *file, int i)
{
	if (i == 0)
		return (openf_read(file));
	else if (i == 11)
		return (openf_append(file));
	else
		return (openf_trunc(file));
}

void	redir_builtins(t_data *data, t_list *curr, int temp_fds[2])
{
	t_list	*to_free;

	to_free = curr;
	if (!to_free)
		return ;
	while (curr)
	{
		if (((char *)curr->content)[0] == '>'
			&& ft_strcmp((char *)curr->content, ">>") == 0)
			handle_output_redir(&curr, temp_fds, 1, &openf_builtins);
		else if (((char *)curr->content)[0] == '>')
			handle_output_redir(&curr, temp_fds, 0, &openf_builtins);
		else if (((char *)curr->content)[0] == '<'
			&& ft_strcmp((char *)curr->content, "<<") == 0)
		{
			dup2(temp_fds[INFILE], INFILE);
			curr = curr->next;
			heredoc(data, (char *)curr->content);
		}
		else if (((char *)curr->content)[0] == '<')
			handle_input_redir(&curr, temp_fds, &openf_builtins);
		curr = curr->next;
	}
	ft_lstclear(&to_free, &free);
}
