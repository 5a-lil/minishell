/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_quote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangtran <dangtran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 09:42:12 by khadj-me          #+#    #+#             */
/*   Updated: 2025/03/20 08:46:00 by dangtran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	strlen_split(char *s, char c)
{
	int	j;

	j = 0;
	if (is_in_charset(*s, "\'\"") == 1)
	{
		j++;
		s++;
		while (is_in_charset(*s, "\'\"") == 0 && *s++)
			j++;
		s++;
		j++;
	}
	else
		while (*s != c && *s++)
			j++;
	return (j);
}

static int	count_words_split(char *s, char c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (*s)
	{
		if (*s && is_in_charset(*s, "\'\"") == 1)
		{
			s++;
			while (*s && is_in_charset(*s, "\'\"") == 0)
				s++;
			i++;
		}
		else if (*s && ((*s != c && *(s + 1) == c) || (*s != c && *(s
						+ 1) == '\0')))
			i++;
		if (s)
			s++;
	}
	return (i);
}

static char	*allocate_word(char **s, char c)
{
	char	*word;
	size_t	i;

	i = 0;
	word = malloc(strlen_split(*s, c) + 1);
	if (!word)
		return (NULL);
	while (**s && **s != c)
	{
		if (is_in_charset(**s, "\'\"") == 1)
			assert_loop_39(&word, s, 0, (int *)&i);
		else
			word[i++] = *(*s)++;
	}
	word[i] = '\0';
	return (word);
}

char	**split_quote(char *s, char c)
{
	size_t	i;
	size_t	k;
	char	**result;

	i = 0;
	k = 0;
	result = malloc((count_words_split(s, c) + 1) * sizeof(char *));
	if (!result || !s)
		return (free(result), NULL);
	skip_loop(&s, c);
	while (*s)
	{
		result[k] = allocate_word(&s, c);
		if (!result[k])
			return (free_char_char(result), NULL);
		k++;
		skip_loop(&s, c);
	}
	result[k] = NULL;
	return (result);
}
