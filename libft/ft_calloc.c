/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangtran <dangtran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:08:20 by khadj-me          #+#    #+#             */
/*   Updated: 2025/03/20 10:07:52 by dangtran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t elementCount, size_t elementSize)
{
	void	*result;

	if (elementCount == 0 || elementSize == 0)
		return (malloc(0));
	result = malloc(elementCount * elementSize);
	if (result == NULL)
		return (result);
	ft_memset(result, 0, elementCount * elementSize);
	return (result);
}
