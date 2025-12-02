/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khadj-me <khalilhadjmes1@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:48:42 by khadj-me          #+#    #+#             */
/*   Updated: 2024/11/14 14:39:49 by khadj-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *pointer, int value, size_t count)
{
	size_t			i;
	unsigned char	*buffer;

	i = 0;
	if (count <= 0)
		return (pointer);
	buffer = (unsigned char *)pointer;
	while (i < count)
		buffer[i++] = (char)value;
	return (pointer);
}

//int main(int argc, char **argv)
//{
//	(void)argc;
//	(void)argv;
//	int array[] = { 54, 85, 20, 63, 21 };
//	size_t size = sizeof( int ) * 3;
//	int length;
//
//	printf("output before :");
//	for( length=0; length<3; length++) {
//		printf( "%d ", array[ length ] );
//	}
//	printf( "\n" );
//
//	if (argc < 2)
//		return (0);
//	if (argv[1][0] == 'm')
//		memset( test, test + 2, length );
//	else if (argv[1][0] == 'f')
//		ft_memset( test, test + 2, length );
//	else
//		return (0);
//
//	printf("output after :");
//	for( length=0; length<3; length++)
//		printf("%d ", array[ length ]);
//	printf("\n");
//}