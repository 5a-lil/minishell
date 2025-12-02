/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khadj-me <khalilhadjmes1@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 20:58:18 by khadj-me          #+#    #+#             */
/*   Updated: 2024/11/27 14:44:36 by khadj-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*print_hexa_ptr(uintptr_t nb, char *result)
{
	if (nb == 0)
		return (result = add(result, "0123456789abcdef"[nb % 16]), result);
	while (nb > 0)
	{
		result = add(result, "0123456789abcdef"[nb % 16]);
		nb /= 16;
	}
	return (result);
}

char	*print_ptr(uintptr_t nb, char *result)
{
	if (!nb)
		return (ft_strdup("(nil)"));
	result = print_hexa_ptr(nb, result);
	result = add(result, 'x');
	result = add(result, '0');
	return (reverse(result), result);
}
