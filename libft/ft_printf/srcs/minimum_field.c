/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimum_field.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khadj-me <khalilhadjmes1@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:31:02 by khadj-me          #+#    #+#             */
/*   Updated: 2024/11/28 15:41:26 by khadj-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*minimum_field(va_list args, const char *string, int *i)
{
	size_t	j;
	int		id;
	int		nb;
	char	*res;
	char	*temp;

	j = 0;
	id = 0;
	while (ft_isdigit(string[j]))
		j++;
	temp = ft_substr(string, 0, j);
	nb = ft_atoi(temp);
	free(temp);
	temp = printf_flags(args, &string[j], i);
	if ((int)ft_strlen(temp) >= nb)
		return (temp);
	res = malloc(nb + ft_strlen(temp) + 1);
	if (!res)
		return (NULL);
	j = 0;
	while (j < nb - ft_strlen(temp))
		res[j++] = ' ';
	while (temp[id])
		res[j++] = temp[id++];
	return (res[j] = '\0', free(temp), res);
}
