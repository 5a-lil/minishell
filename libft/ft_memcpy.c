/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khadj-me <khalilhadjmes1@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:39:45 by khadj-me          #+#    #+#             */
/*   Updated: 2024/11/14 14:40:23 by khadj-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *destination, const void *source, size_t size)
{
	size_t			i;
	unsigned char	*dest_buffer;
	unsigned char	*src_buffer;

	i = 0;
	if (!destination && !source)
		return (NULL);
	if (size <= 0)
		return (destination);
	dest_buffer = (unsigned char *)destination;
	src_buffer = (unsigned char *)source;
	while (i < size)
	{
		dest_buffer[i] = src_buffer[i];
		i++;
	}
	return (destination);
}

//int main(int argc, char **argv)
//{
//	(void)argc;
//	(void)argv;
//	char test[] = "Salam 3likom";
//	int length = sizeof( int ) * 1;
//	if (argc < 2)
//		return (0);
//	if (argv[1][0] == 'm')
//		memcpy( test, test + 2, length );
//	else if (argv[1][0] == 'f')
//		ft_memcpy( test, test + 2, length );
//	else
//		return (0);
//
//	printf("output :");
//	for( length=0; length<(int)strlen(test); length++ )
//		printf("%d ", test[ length ]);
//	printf("\n");
//}