/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dot_flag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khadj-me <khalilhadjmes1@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:28:45 by khadj-me          #+#    #+#             */
/*   Updated: 2024/11/27 14:53:03 by khadj-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*dot_flag(va_list args, const char *string, int *i)
{
	size_t	j;
	int		nb;
	char	*res;
	char	*temp;

	j = 1;
	while (ft_isdigit(string[j]))
		j++;
	temp = ft_substr(string, 1, j - 1);
	nb = ft_atoi(temp);
	free(temp);
	temp = printf_flags(args, &string[j], i);
	if (temp[0] == '-' && nb != 0 && (string[j] == 'd' || string[j] == 'i'))
		nb++;
	if (string[j] == 's')
		return (res = ft_substr(temp, 0, nb), free(temp), res);
	if ((int)ft_strlen(temp) >= nb)
		return (temp);
	res = malloc(nb + ft_strlen(temp) + 1);
	if (!res || j == 1)
		return (free(res), free(temp), NULL);
	j = 0;
	while (j < nb - ft_strlen(temp))
		res[j++] = '0';
	return (assert(res, temp, j), free(temp), res);
}
