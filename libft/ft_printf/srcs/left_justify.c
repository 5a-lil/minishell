/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left_justify.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khadj-me <khalilhadjmes1@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:27:53 by khadj-me          #+#    #+#             */
/*   Updated: 2024/11/28 15:45:09 by khadj-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*left_justify(va_list args, const char *string, int *i, int k)
{
	size_t	j;
	int		nb;
	char	*res;
	char	*temp;

	j = k;
	while (ft_isdigit(string[j]))
		j++;
	temp = ft_substr(string, k, j - k);
	nb = ft_atoi(temp);
	free(temp);
	temp = printf_flags(args, &string[j], i);
	if (!temp)
		nb--;
	res = malloc(nb + ft_strlen(temp) + 1);
	j = 0;
	while (j < ft_strlen(temp))
	{
		res[j] = temp[j];
		j++;
	}
	while ((int)j < nb)
		res[j++] = ' ';
	res[j] = '\0';
	return (free(temp), res);
}
