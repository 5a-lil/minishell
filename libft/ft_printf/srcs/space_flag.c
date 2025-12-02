/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   space_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khadj-me <khalilhadjmes1@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:25:05 by khadj-me          #+#    #+#             */
/*   Updated: 2024/11/27 14:51:40 by khadj-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*space_flag(va_list args, const char *string, int *i)
{
	char	*temp;
	char	*result;

	temp = NULL;
	temp = printf_flags(args, &string[1], i);
	if (ft_strchr(string, 's'))
		return (temp);
	if (temp[0] == '-')
		return (temp);
	else if (ft_isdigit(temp[0]) == 1)
	{
		result = ft_strjoin(" ", temp);
		return (free(temp), result);
	}
	else
		return (free(temp), NULL);
	return (free(temp), result);
}
