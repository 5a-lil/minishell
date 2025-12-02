/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khadj-me <khalilhadjmes1@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 10:59:08 by khadj-me          #+#    #+#             */
/*   Updated: 2024/11/14 14:32:34 by khadj-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int character)
{
	if (character >= 'A' && character <= 'Z')
		return (character + 32);
	else
		return (character);
}

//int main(int argc, char **argv)
//{
//	(void)argc;
//	if (argc < 2)
//		return (0);
//	printf("expected : %c\n", tolower(argv[1][0]));
//	printf("output : %c\n", ft_tolower(argv[1][0]));
//}
