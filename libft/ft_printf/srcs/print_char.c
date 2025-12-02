/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khadj-me <khalilhadjmes1@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:22:47 by khadj-me          #+#    #+#             */
/*   Updated: 2024/11/28 15:37:28 by khadj-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*print_char(char c, int *i)
{
	char	*result;

	(void)i;
	if (c == 0)
		return (putchar_fd(c, 1, i), NULL);
	result = malloc(2);
	if (!result)
		return (NULL);
	result[0] = c;
	result[1] = '\0';
	return (result);
}
