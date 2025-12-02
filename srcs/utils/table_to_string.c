/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_to_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khadj-me <khalilhadjmes1@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:01:05 by khadj-me          #+#    #+#             */
/*   Updated: 2025/03/14 19:58:01 by khadj-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*table_to_string(char **table)
{
	int		i;
	char	*result;
	char	*space;
	char	*to_free;

	if (!table || !table[0])
		return (NULL);
	i = 0;
	result = ft_strdup(table[i++]);
	space = NULL;
	to_free = NULL;
	while (table[i])
	{
		to_free = result;
		space = ft_strjoin(" ", table[i++]);
		result = ft_strjoin(result, space);
		free(to_free);
		free(space);
	}
	return (result);
}
