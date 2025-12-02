/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khadj-me <khalilhadjmes1@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 09:46:51 by khadj-me          #+#    #+#             */
/*   Updated: 2025/03/21 07:20:02 by khadj-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exit_free(t_list *tokens, t_list *env_vars, int err_code)
{
	ft_lstclear(&tokens, &free);
	ft_lstclear(&env_vars, &free);
	exit(err_code);
}

void	free_data(t_data *data)
{
	int	i;

	i = 0;
	if (!data)
		return ;
	ft_lstclear(&data->env_vars, &free);
	data->env_vars = NULL;
	close_files(data->stds);
	if (data->stdin_copy != -1)
		close(data->stdin_copy);
	free(data->prompt);
}
