/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlen_till_char.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khadj-me <khalilhadjmes1@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 11:52:54 by khadj-me          #+#    #+#             */
/*   Updated: 2025/02/27 12:11:46 by khadj-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	strlen_till_char(const char *str, const char *charset)
{
	int	i;

	i = 0;
	while (str[i] && is_in_charset(str[i], charset) == 0)
		i++;
	return (i);
}
