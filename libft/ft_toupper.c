/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khadj-me <khalilhadjmes1@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 10:54:24 by khadj-me          #+#    #+#             */
/*   Updated: 2025/01/15 08:12:40 by khadj-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int character)
{
	if (character >= 'a' && character <= 'z')
		return (character - 32);
	else
		return (character);
}

//int main(int argc, char **argv)
//{
//	(void)argc;
//	if (argc < 2)
//		return (0);
//	printf("expected : %c\n", toupper(argv[1][0]));
//	printf("output : %c\n", ft_toupper(argv[1][0]));
//}