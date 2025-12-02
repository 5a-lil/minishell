/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_quote_loop.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangtran <dangtran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 12:56:28 by dangtran          #+#    #+#             */
/*   Updated: 2025/03/20 08:45:49 by dangtran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	skip_loop(char **s, char c)
{
	while (**s == c && **s)
		(*s)++;
}

void	assert_loop_39(char **result, char **s, int k, int *i)
{
	if (**s && **s == '\'')
	{
		(*s)++;
		while (**s && is_in_charset(**s, "\'") == 0)
			result[k][(*i)++] = *(*s)++;
		if (**s)
			(*s)++;
	}
	else if (**s && **s == '\"')
	{
		(*s)++;
		while (**s && is_in_charset(**s, "\"") == 0)
			result[k][(*i)++] = *(*s)++;
		if (**s)
			(*s)++;
	}
}
