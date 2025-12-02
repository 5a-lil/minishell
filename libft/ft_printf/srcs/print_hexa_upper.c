/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa_upper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khadj-me <khalilhadjmes1@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 11:26:45 by khadj-me          #+#    #+#             */
/*   Updated: 2024/11/28 14:57:28 by khadj-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*print_hexa_upper(unsigned int nb, char *result)
{
	if (nb == 0)
		return (result = add(result, "0123456789ABCDEF"[nb % 16]), result);
	while (nb > 0)
	{
		result = add(result, "0123456789ABCDEF"[nb % 16]);
		nb /= 16;
	}
	return (reverse(result), result);
}
