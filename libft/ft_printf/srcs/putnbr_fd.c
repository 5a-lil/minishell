/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_fd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khadj-me <khalilhadjmes1@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:52:32 by khadj-me          #+#    #+#             */
/*   Updated: 2024/11/25 18:51:09 by khadj-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*print_nbr(long nb, char *result)
{
	if (nb < 0)
	{
		nb *= -1;
		while (nb != 0)
		{
			result = add(result, "0123456789"[nb % 10]);
			nb /= 10;
		}
		result = add(result, '-');
		return (reverse(result), result);
	}
	if (nb == 0)
		return (result = add(result, "0123456789"[nb % 10]), result);
	while (nb != 0)
	{
		result = add(result, "0123456789"[nb % 10]);
		nb /= 10;
	}
	return (reverse(result), result);
}

/*int main(int argc, char **argv)
{
	(void)argc;
	ft_putnbr_fd(atoi(argv[1]), 1);
}*/
