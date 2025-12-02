/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khadj-me <khalilhadjmes1@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 09:07:45 by khadj-me          #+#    #+#             */
/*   Updated: 2024/11/14 14:32:49 by khadj-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
		if (c == set[i++])
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	char	*result;
	size_t	start;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	start = 0;
	while (is_in_set(s1[start], set) == 1 && s1[start])
		start++;
	end = ft_strlen(s1);
	while (is_in_set(s1[end - 1], set) == 1 && end > start)
		end--;
	result = malloc(sizeof(char) * (end - start) + 1);
	if (!result)
		return (NULL);
	while (start < end && s1[start])
		result[i++] = s1[start++];
	result[i] = '\0';
	return (result);
}

//int	main(int argc, char **argv)
//{
//	(void)argc;
//	if (argc < 3)
//		return (0);
//	printf("output : %s\n", ft_strtrim(argv[1], argv[2]));
//}