/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putstr_fd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khadj-me <khalilhadjmes1@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:42:40 by khadj-me          #+#    #+#             */
/*   Updated: 2024/11/17 12:03:31 by khadj-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	putstr_fd(const char *s, int fd, int *i)
{
	if (!s)
		return (putstr_fd("(null)", fd, i));
	while (*s)
		putchar_fd(*s++, fd, i);
}

/*int main(int argc, char **argv)
{
	(void)argc;
	ft_putstr_fd(argv[1], 1);
}*/
