/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_ign_quote.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangtran <dangtran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:16:34 by khadj-me          #+#    #+#             */
/*   Updated: 2025/03/20 08:45:41 by dangtran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	strlen_split(const char *s, char c)
{
	int	j;

	j = 0;
	while (*s && *s++ != c)
	{
		if (*s && *s == '\'' && j++ != -1)
		{
			s++;
			while (*s && *s++ != '\'')
				j++;
			if (*s)
				j++;
		}
		else if (*s && *s == '\"' && j++ != -1)
		{
			s++;
			while (*s && *s++ != '\"')
				j++;
			if (*s)
				j++;
		}
		j++;
	}
	return (j + 1);
}

static int	count_words_split(char const *s, char c)
{
	int	i;

	i = 0;
	while (*s)
	{
		if ((*s != c && *(s + 1) == c) || (*s != c && *(s + 1) == '\0'))
			i++;
		s++;
	}
	return (i);
}

static void	skip_delimiters(const char **s, char c)
{
	while (**s == c && **s)
		(*s)++;
}

char	**split_ign_quote(char const *s, char c)
{
	size_t	i;
	size_t	k;
	char	**result;

	i = 0;
	k = 0;
	result = malloc((count_words_split(s, c) + 1) * sizeof(char *));
	if (!result || !s)
		return (free(result), NULL);
	skip_delimiters(&s, c);
	while (*s)
	{
		result[k] = malloc(strlen_split(s, c) + 1);
		if (!result[k])
			return (free_char_char(result), NULL);
		handle_non_quote_split(&s, result[k], &i, c);
		result[k++][i] = '\0';
		i = 0;
		skip_delimiters(&s, c);
	}
	result[k] = NULL;
	return (result);
}
