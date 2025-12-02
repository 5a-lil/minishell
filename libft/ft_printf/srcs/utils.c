/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khadj-me <khalilhadjmes1@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:46:16 by khadj-me          #+#    #+#             */
/*   Updated: 2024/11/25 18:27:46 by khadj-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	reverse(char *str)
{
	int		first;
	int		last;
	char	temp;

	first = 0;
	last = ft_strlen(str) - 1;
	while (first < last)
	{
		temp = str[first];
		str[first] = str[last];
		str[last] = temp;
		first++;
		last--;
	}
}

char	*add(char *str, char c)
{
	int		i;
	char	*result;

	i = 0;
	if (!str)
		return (free(str), result = malloc(2), result[0] = c, result[1] = '\0',
			result);
	result = malloc(ft_strlen(str) + 2);
	if (!result)
		return (NULL);
	while (str[i])
	{
		result[i] = str[i];
		i++;
	}
	result[i++] = c;
	result[i] = '\0';
	return (free(str), result);
}
