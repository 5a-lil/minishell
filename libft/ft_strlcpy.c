/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khadj-me <khalilhadjmes1@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 08:57:35 by khadj-me          #+#    #+#             */
/*   Updated: 2024/11/14 14:33:38 by khadj-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	int	i;

	i = 0;
	if ((int)size < 0)
		size = ft_strlen(src) + 1;
	if ((int)size == 0)
		return (ft_strlen(src));
	while (i < (int)size - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

//int main(int argc, char **argv)
//{
//	(void)argc;
//	(void)argv;
//	char test1[] = "SALAMMM";
//	char test2[] = "3LIKOM";
//
//	if (argc < 2)
//		return (0);
//	ft_strlcpy(test1, test2, atoi(argv[1]));
//	printf("output : %s\n", test1);
//}
