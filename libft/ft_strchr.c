/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khadj-me <khalilhadjmes1@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:29:51 by khadj-me          #+#    #+#             */
/*   Updated: 2025/01/08 10:17:12 by khadj-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int searchedChar)
{
	size_t	i;

	i = 0;
	while (*s)
	{
		if (*s == (char)searchedChar)
			return ((char *)s);
		s++;
	}
	if (s[i] == (char)searchedChar)
		return ((char *)s);
	return (NULL);
}

//int main(int argc, char **argv)
//{
//	(void)argc;
//	if (argc < 3)
//		return (0);
//	printf("expected : %s\n", strchr(argv[1], argv[2][0]));
//	printf("output : %s\n", ft_strchr(argv[1], argv[2][0]));
//}