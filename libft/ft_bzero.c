/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangtran <dangtran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:19:09 by khadj-me          #+#    #+#             */
/*   Updated: 2025/03/20 10:07:38 by dangtran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*buffer;

	if (n == 0)
		return ;
	i = 0;
	buffer = (char *)s;
	while (i < n)
		buffer[i++] = 0;
}
