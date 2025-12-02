/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khadj-me <khalilhadjmes1@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 09:42:12 by khadj-me          #+#    #+#             */
/*   Updated: 2025/01/10 14:14:46 by khadj-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	strlen_split(const char *s, char c)
{
	int	j;

	j = 0;
	while (*s != c && *s++)
		j++;
	return (j);
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

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	k;
	char	**result;

	i = 0;
	k = 0;
	result = malloc((count_words_split(s, c) + 1) * sizeof(char *));
	if (!result || !s)
		return (free(result), NULL);
	while (*s == c && *s)
		s++;
	while (*s)
	{
		result[k] = malloc(strlen_split(s, c) + 1);
		if (!result[k])
			return (free_char_char(result), NULL);
		while (*s != c && *s)
			result[k][i++] = *s++;
		result[k++][i] = '\0';
		i = 0;
		while (*s == c && *s)
			s++;
	}
	return (result[k] = NULL, result);
}

//int	main(int argc, char **argv)
//{
//	(void)argc;
//	int i;
//	char **test;
//
//	i = 0;
//	if (argc < 3)
//		return (0);
//	test = ft_split(argv[1], argv[2][0]);
//	while (test[i] != NULL)
//	{
//		printf("output test[%d] : %s\n", i, test[i]);
//		free(test[i++]);
//	}
//	free(test);
//}