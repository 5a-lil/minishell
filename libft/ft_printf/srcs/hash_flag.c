/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_flag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khadj-me <khalilhadjmes1@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:26:47 by khadj-me          #+#    #+#             */
/*   Updated: 2024/11/27 14:27:14 by khadj-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*hash_flag(va_list args, const char *string)
{
	char	*temp;
	char	*result;

	temp = NULL;
	if (string[1] == 'x')
	{
		temp = print_hexa_lower(va_arg(args, uintptr_t), temp);
		if (temp[0] != '0')
			result = ft_strjoin("0x", temp);
		else
			return (temp);
		return (free(temp), result);
	}
	else if (string[1] == 'X')
	{
		temp = print_hexa_upper(va_arg(args, uintptr_t), temp);
		if (temp[0] != '0')
			result = ft_strjoin("0X", temp);
		else
			return (temp);
		return (free(temp), result);
	}
	else
		return (NULL);
}
