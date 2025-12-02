/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa_lower.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khadj-me <khalilhadjmes1@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 11:54:12 by khadj-me          #+#    #+#             */
/*   Updated: 2024/11/25 17:52:03 by khadj-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*print_hexa_lower(unsigned int nb, char *result)
{
	if (nb == 0)
		return (result = add(result, "0123456789abcdef"[nb % 16]), result);
	while (nb > 0)
	{
		result = add(result, "0123456789abcdef"[nb % 16]);
		nb /= 16;
	}
	return (reverse(result), result);
}
