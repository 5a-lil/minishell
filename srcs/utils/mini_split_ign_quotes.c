/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_split_ign_quotes.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangtran <dangtran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 12:49:22 by dangtran          #+#    #+#             */
/*   Updated: 2025/03/20 08:45:21 by dangtran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_single_quote_split(const char **s, char *result, size_t *i)
{
	result[(*i)++] = *(*s)++;
	while (**s && **s != '\'')
		result[(*i)++] = *(*s)++;
	if (**s)
		result[(*i)++] = *(*s)++;
}

void	handle_double_quote_split(const char **s, char *result, size_t *i)
{
	result[(*i)++] = *(*s)++;
	while (**s && **s != '\"')
		result[(*i)++] = *(*s)++;
	if (**s)
		result[(*i)++] = *(*s)++;
}

void	handle_non_quote_split(const char **s, char *result, size_t *i, char c)
{
	while (**s != c && **s)
	{
		if (**s == '\'')
			handle_single_quote_split(s, result, i);
		else if (**s == '\"')
			handle_double_quote_split(s, result, i);
		else
			result[(*i)++] = *(*s)++;
	}
}
