/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_dir.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khadj-me <khalilhadjmes1@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 10:06:51 by khadj-me          #+#    #+#             */
/*   Updated: 2025/03/21 08:40:59 by khadj-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	is_dir(t_list **tokens, t_data *data)
{
	int	temp;
	DIR	*fd;

	fd = opendir((const char *)(*tokens)->content);
	if (fd == NULL)
	{
		temp = open((const char *)(*tokens)->content, O_RDONLY);
		if (errno == 13)
			data->exit_code = 126;
		else
			data->exit_code = 127;
		write(2, " ", 1);
		ft_putendl_fd(strerror(errno), 2);
		if (temp != -1)
			close(temp);
	}
	else
	{
		data->exit_code = 126;
		ft_putendl_fd(" Is a directory\n", 2);
	}
	closedir(fd);
	(*tokens) = (*tokens)->next;
}
