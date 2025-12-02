/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khadj-me <khalilhadjmes1@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 12:49:58 by khadj-me          #+#    #+#             */
/*   Updated: 2025/03/21 15:02:16 by khadj-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	env(t_list **tokens, t_list *env_vars)
{
	if (env_vars)
		print_tokens(env_vars);
	while ((*tokens) != NULL && is_in_charset(((char *)(*tokens)->content)[0],
			"|<>") == 0)
		(*tokens) = (*tokens)->next;
}
