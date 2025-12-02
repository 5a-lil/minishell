/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putchar_fd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khadj-me <khalilhadjmes1@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:38:18 by khadj-me          #+#    #+#             */
/*   Updated: 2024/11/16 14:37:04 by khadj-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	putchar_fd(char c, int fd, int *i)
{
	write(fd, &c, 1);
	(*i)++;
}

/*int main(int argc, char **argv)
{
	(void)argc;
	ft_putchar_fd(argv[1][0], 1);
}*/
