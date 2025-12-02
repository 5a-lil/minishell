/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangtran <dangtran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 12:23:43 by khadj-me          #+#    #+#             */
/*   Updated: 2025/03/20 08:46:10 by dangtran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	strlen_quote(const char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (is_in_charset(str[i], "\'\"") == 1)
	{
		j++;
		i++;
		while (is_in_charset(str[i], "\'\"") == 0 && str[i++])
			j++;
		i++;
		j++;
	}
	else
		j++;
	return (j);
}

static void	handle_single_quote(const char **source, char *result, size_t *i)
{
	(*source)++;
	while (**source && is_in_charset(**source, "\'") == 0)
		result[(*i)++] = *(*source)++;
	if (**source)
		(*source)++;
}

static void	handle_double_quote(const char **source, char *result, size_t *i)
{
	(*source)++;
	while (**source && is_in_charset(**source, "\"") == 0)
		result[(*i)++] = *(*source)++;
	if (**source)
		(*source)++;
}

char	*strdup_quote(const char *source)
{
	size_t	i;
	char	*result;

	if (!source)
		return (ft_strdup("(null)"));
	i = 0;
	result = malloc(strlen_quote(source) * sizeof(char) + 1);
	if (!result)
		return (NULL);
	while (*source)
	{
		if (*source == '\'')
			handle_single_quote(&source, result, &i);
		else if (*source == '\"')
			handle_double_quote(&source, result, &i);
		else
			result[i++] = *source++;
	}
	result[i] = '\0';
	return (result);
}
