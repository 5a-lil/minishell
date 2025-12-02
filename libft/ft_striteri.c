/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khadj-me <khalilhadjmes1@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:34:31 by khadj-me          #+#    #+#             */
/*   Updated: 2024/11/14 14:33:50 by khadj-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

//void	ft_toupper_ex(unsigned int i, char *c)
//{
//	if (c[0] >= 'a' && c[0] <= 'z')
//		c[0] -= 32;
//	else
//		return ;
//}
//
//int	main(int argc, char **argv)
//{
//	char	*test;
//
//	if (argc < 2)
//		return (0);
//	test = argv[1];
//	printf("output before : %s\n", test);
//	ft_striteri(test, ft_toupper_ex);
//	printf("output after : %s\n", test);
//}
