/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khadj-me <khalilhadjmes1@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:26:05 by khadj-me          #+#    #+#             */
/*   Updated: 2024/11/14 14:40:04 by khadj-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *destination, const void *source, size_t size)
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
	if (dest_buffer > src_buffer)
		while (size--)
			dest_buffer[size] = src_buffer[size];
	else
	{
		while (i < size)
		{
			dest_buffer[i] = src_buffer[i];
			i++;
		}
	}
	return (destination);
}

//int main(int argc, char **argv)
//{
//	(void)argc;
//	(void)argv;
//	char test[] = "Salam 3likom";
//	int length = sizeof( int ) * 1;
//
//	if (argc < 2)
//		return (0);
//	if (argv[1][0] == 'm')
//		memmove( test, test + 2, length );
//	else if (argv[1][0] == 'f')
//		ft_memmove( test, test + 2, length );
//	else
//		return (0);
//
//	printf("output :");
//	for( length=0; length<(int)strlen(test); length++)
//		printf("%c ", test[length]);
//	printf("\n");
//}