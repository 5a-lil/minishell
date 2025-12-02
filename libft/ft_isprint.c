/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khadj-me <khalilhadjmes1@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:41:54 by khadj-me          #+#    #+#             */
/*   Updated: 2024/11/14 15:16:22 by khadj-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (true);
	else
		return (false);
}

// int main(int argc, char **argv)
// {
// 	(void)argv;
// 	(void)argc;
// 	if (argc < 2)
// 		return (0);
// 	printf("expected : %d\n", isprint('\n'));
// 	printf("output : %d\n", ft_isprint('\n'));
// }