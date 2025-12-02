/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khadj-me <khalilhadjmes1@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:47:45 by khadj-me          #+#    #+#             */
/*   Updated: 2025/02/26 16:51:15 by khadj-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (*str++)
		i++;
	return (i);
}

//int	main(int argc, char **argv)
//{
//	(void)argc;
//	if (argc < 2)
//		return (0);
//	printf("expected : %d\n", strlen(argv[1]));
//	printf("output : %d\n", ft_strlen(argv[1]));
//}