/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_replace.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khadj-me <khalilhadjmes1@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 09:46:57 by khadj-me          #+#    #+#             */
/*   Updated: 2025/02/12 10:02:44 by khadj-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*free_and_replace(char *to_free, char *to_replace)
{
	if (!to_free || !to_replace)
		return (NULL);
	free(to_free);
	to_free = NULL;
	return (to_replace);
}
