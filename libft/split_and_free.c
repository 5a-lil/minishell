/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_and_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khadj-me <khalilhadjmes1@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 13:50:51 by khadj-me          #+#    #+#             */
/*   Updated: 2025/01/23 20:38:23 by khadj-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**split_and_free(char *to_split, char splitter)
{
	char	**result;

	result = ft_split(to_split, splitter);
	if (!result)
		return (NULL);
	return (free(to_split), result);
}
