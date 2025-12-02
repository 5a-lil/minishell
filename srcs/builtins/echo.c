/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khadj-me <khalilhadjmes1@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 10:25:08 by khadj-me          #+#    #+#             */
/*   Updated: 2025/03/21 10:38:10 by khadj-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	dash_n_flag(t_list **tokens)
{
	while ((*tokens) != NULL && is_dash_n_flag((char *)(*tokens)->content) == 1)
		(*tokens) = (*tokens)->next;
	if ((*tokens) == NULL)
		return ;
	while ((*tokens)->next != NULL)
	{
		printf("%s ", (char *)(*tokens)->content);
		(*tokens) = (*tokens)->next;
	}
	printf("%s", (char *)(*tokens)->content);
	(*tokens) = (*tokens)->next;
}

int	is_dash_n_flag(char *token)
{
	int	i;

	i = 0;
	if (!token)
		return (FALSE);
	if (token[0] != '-')
		return (FALSE);
	while (token[++i])
		if (token[i] != 'n')
			return (FALSE);
	return (TRUE);
}

void	echo(t_list **tokens)
{
	(*tokens) = (*tokens)->next;
	if (*tokens == NULL)
	{
		printf("\n");
		return ;
	}
	if (is_dash_n_flag((char *)(*tokens)->content) == 1)
		dash_n_flag(tokens);
	else
	{
		while ((*tokens)->next != NULL)
		{
			printf("%s ", (char *)(*tokens)->content);
			(*tokens) = (*tokens)->next;
		}
		if (*tokens)
			printf("%s\n", (char *)(*tokens)->content);
		(*tokens) = (*tokens)->next;
	}
}
