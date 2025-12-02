/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_unsigned_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khadj-me <khalilhadjmes1@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:05:46 by khadj-me          #+#    #+#             */
/*   Updated: 2024/11/25 18:55:02 by khadj-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*print_unsigned_nbr(unsigned int nb, char *result)
{
	if (nb == 0)
		return (result = add(result, "0123456789"[nb % 10]), result);
	while (nb > 0)
	{
		result = add(result, "0123456789"[nb % 10]);
		nb /= 10;
	}
	return (reverse(result), result);
}
