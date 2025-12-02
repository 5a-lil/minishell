/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strchr_table.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khadj-me <khalilhadjmes1@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 08:48:39 by khadj-me          #+#    #+#             */
/*   Updated: 2025/01/23 20:38:09 by khadj-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	strchr_table(char **table, char to_search)
{
	int	i;

	i = -1;
	while (table[++i])
		if (ft_strchr(table[i], to_search) != NULL)
			return (1);
	return (0);
}
