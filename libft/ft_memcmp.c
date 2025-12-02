/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khadj-me <khalilhadjmes1@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:18:17 by khadj-me          #+#    #+#             */
/*   Updated: 2024/11/14 14:40:30 by khadj-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *pointer1, const void *pointer2, size_t size)
{
	size_t			i;
	unsigned char	*buf1;
	unsigned char	*buf2;

	i = 0;
	buf1 = (unsigned char *)pointer1;
	buf2 = (unsigned char *)pointer2;
	if (size == 0)
		return (0);
	while (*buf1 == *buf2 && i < size - 1)
	{
		buf2++;
		buf1++;
		i++;
	}
	return ((unsigned int)*buf1 - (unsigned int)*buf2);
}

//int	main(int argc, char *argv[])
//{
//	(void)argc;
//	char *test1 = argv[1];
//	char *test2 = argv[2];
//	if (argc < 4)
//		return (0);
//	printf("expected : %d\n", memcmp(test1, test2, atoi(argv[3])));
//	printf("output : %d\n", ft_memcmp(test1, test2, atoi(argv[3])));
//}