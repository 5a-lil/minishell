/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_char_table.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khadj-me <khalilhadjmes1@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:09:19 by khadj-me          #+#    #+#             */
/*   Updated: 2025/01/25 10:38:04 by khadj-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_char_char(char **tofree)
{
	int	i;

	i = 0;
	if (!tofree)
		return ;
	while (tofree[i])
		free(tofree[i++]);
	free(tofree);
}
