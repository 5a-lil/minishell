/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangtran <dangtran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:03:51 by khadj-me          #+#    #+#             */
/*   Updated: 2025/03/20 10:07:32 by dangtran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *theString)
{
	int	i;
	int	result;
	int	sign;

	i = 0;
	result = 0;
	sign = 1;
	while ((theString[i] == 32 || theString[i] == '\t' || theString[i] == '\n'
			|| theString[i] == '\r' || theString[i] == '\v'
			|| theString[i] == '\f') && theString[i])
		i++;
	while (theString[i] == '+' || theString[i] == '-')
	{
		if (theString[i] == '-')
			sign *= -1;
		if (theString[i + 1] == '+' || theString[i + 1] == '-')
			return (result);
		i++;
	}
	while (theString[i] <= '9' && theString[i] >= '0')
	{
		result = result * 10 + theString[i] - '0';
		i++;
	}
	return (result * sign);
}
