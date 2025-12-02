/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plus_flag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khadj-me <khalilhadjmes1@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:24:29 by khadj-me          #+#    #+#             */
/*   Updated: 2024/11/27 14:50:59 by khadj-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*plus_flag(va_list args)
{
	char	*temp;
	char	*result;

	temp = NULL;
	temp = print_nbr(va_arg(args, int), temp);
	if (temp[0] == '-')
		return (temp);
	else if (ft_isdigit(temp[0]) == 1)
	{
		result = ft_strjoin("+", temp);
		return (free(temp), result);
	}
	else
		return (NULL);
	return (free(temp), result);
}
