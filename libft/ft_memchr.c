/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khadj-me <khalilhadjmes1@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:58:12 by khadj-me          #+#    #+#             */
/*   Updated: 2024/11/14 14:40:37 by khadj-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *memoryBlock, int searchedChar, size_t size)
{
	size_t	i;
	char	*buffer;

	i = 0;
	buffer = (char *)memoryBlock;
	while (i < size)
	{
		if (buffer[i] == (char)searchedChar)
			return (&buffer[i]);
		i++;
	}
	return (NULL);
}

//int main(int argc, char **argv)
//{
//	(void)argc;
//	char test1[] = "SALAM 3LIKOM";
//	if (argc < 2)
//		return (0);
//	void * test = ft_memchr(test1, argv[1][0], 12);
//	printf("expected : %s\n", (char *)test);
//	printf("output : %s\n", (char *)test);
//}