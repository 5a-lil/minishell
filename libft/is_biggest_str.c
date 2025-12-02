/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_biggest_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khadj-me <khalilhadjmes1@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 17:32:59 by khadj-me          #+#    #+#             */
/*   Updated: 2025/02/27 12:11:07 by khadj-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*is_biggest_str(const char *str1, const char *str2, char *charset,
		int (*f)(const char *, const char *))
{
	if (f(str1, charset) > f(str2, charset))
		return ((char *)str1);
	else
		return ((char *)str2);
}
