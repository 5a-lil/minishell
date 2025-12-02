/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_number.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khadj-me <khalilhadjmes1@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:17:16 by khadj-me          #+#    #+#             */
/*   Updated: 2025/03/18 17:45:18 by khadj-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_number(const char *to_check)
{
	if (!to_check)
		return (0);
	if ((*to_check == '+' || *to_check == '-') && ft_isdigit(*(to_check
				+ 1)) == 1)
		to_check++;
	while (*to_check)
		if (ft_isdigit(*to_check++) == 0)
			return (0);
	return (1);
}
