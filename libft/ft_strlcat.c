/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khadj-me <khalilhadjmes1@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 10:15:51 by khadj-me          #+#    #+#             */
/*   Updated: 2024/11/14 14:33:40 by khadj-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int	i;
	int	j;
	int	length;

	i = 0;
	j = ft_strlen(dst);
	if ((int)size < 0)
		size = ft_strlen(src) + j + 1;
	if ((int)size < j)
		return (ft_strlen(src) + size);
	else
		length = ft_strlen(src) + j;
	while (j < (int)size - 1 && src[i])
		dst[j++] = src[i++];
	dst[j] = '\0';
	return (length);
}

//int	main(int argc, char **argv)
//{
//	(void)argc;
//	(void)argv;
//	char dest[30];
//	memset(dest, 0, 30);
//	char * src = (char *)"AAAAAAAAA";
//	dest[0] = 'B';
//	printf("output return : %ld\n", ft_strlcat(dest, src, 1));
//	printf("output string : %s\n", dest);
//	memset(dest, 'B', 4);
//	printf("output return : %ld\n", ft_strlcat(dest, src, 3));
//	printf("output string : %s\n", dest);
//	printf("output return : %ld\n", ft_strlcat(dest, src, 6));
//	printf("output string : %s\n", dest);
//}