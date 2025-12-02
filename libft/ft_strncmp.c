/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khadj-me <khalilhadjmes1@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:30:13 by khadj-me          #+#    #+#             */
/*   Updated: 2024/11/14 14:33:16 by khadj-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *first, const char *second, size_t length)
{
	size_t	i;

	i = 0;
	if (length == 0)
		return (0);
	while (i < length - 1 && *first && *first == *second)
	{
		first++;
		second++;
		i++;
	}
	return ((unsigned char)*first - (unsigned char)*second);
}

//int main(int argc, char *argv[])
//{
//	(void)argc;
//	char *test1;
//	char *test2;
//	if (argc < 4)
//		return (0);
//	test1 = argv[1];
// 	test2 = argv[2];
//
//	printf("expected : %d\n", strncmp(test1, test2, atoi(argv[3])));
//	printf("output : %d\n", ft_strncmp(test1, test2, atoi(argv[3])));
//}