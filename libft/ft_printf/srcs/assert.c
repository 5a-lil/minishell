/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khadj-me <khalilhadjmes1@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:52:31 by khadj-me          #+#    #+#             */
/*   Updated: 2024/11/27 14:52:50 by khadj-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	assert(char *res, char *temp, int j)
{
	int	id;

	id = 0;
	while (temp[id])
	{
		if (temp[id] == '-')
		{
			temp[id] = '0';
			res[0] = '-';
			continue ;
		}
		res[j++] = temp[id++];
	}
	res[j] = '\0';
}
