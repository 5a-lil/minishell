/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khadj-me <khalilhadjmes1@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 10:28:16 by khadj-me          #+#    #+#             */
/*   Updated: 2025/03/18 17:46:38 by khadj-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exit_bash(t_list **tokens, t_data *data)
{
	if ((*tokens)->next != NULL)
	{
		(*tokens) = (*tokens)->next;
		if ((*tokens)->next != NULL
			&& is_in_charset(((char *)(*tokens)->next->content)[0], "|<>") == 0)
		{
			data->exit_code = 1;
			ft_putendl_fd(" too many arguments", 2);
			return ;
		}
		if (is_number((const char *)(*tokens)->content) == 1)
		{
			data->exit_code = ft_atoi((const char *)(*tokens)->content);
			data->end_tty = 1;
			return ;
		}
		else
		{
			ft_putendl_fd(" numeric argument required", 2);
			data->exit_code = 2;
			return ;
		}
	}
	data->end_tty = 1;
}
