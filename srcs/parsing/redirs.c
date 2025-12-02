/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khadj-me <khalilhadjmes1@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 11:50:28 by khadj-me          #+#    #+#             */
/*   Updated: 2025/03/22 07:16:47 by khadj-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	open_file_read(char *file)
{
	int	fd;

	fd = open(file, O_RDWR, 0644);
	if (fd == -1)
		perror(file);
	return (fd);
}

static int	open_file_append(char *file)
{
	int	fd;

	fd = open(file, O_RDWR | O_APPEND | O_CREAT, 0644);
	if (fd == -1)
		perror(file);
	return (fd);
}

static int	open_file_trunc(char *file)
{
	int	fd;

	fd = open(file, O_RDWR | O_TRUNC | O_CREAT, 0644);
	if (fd == -1)
		perror(file);
	return (fd);
}

int	open_file(char *file, int i)
{
	if (i == 0)
		return (open_file_read(file));
	else if (i == 11)
		return (open_file_append(file));
	else
		return (open_file_trunc(file));
}

void	redir(t_list *curr, int temp_fds[2], t_data *data)
{
	t_list	*to_free;

	to_free = curr;
	if (!to_free)
		return ;
	while (curr)
	{
		mini_handle_output_redir(&curr, temp_fds);
		mini_handle_input_redir(&curr, temp_fds, data);
		curr = curr->next;
	}
	ft_lstclear(&to_free, &free);
}
