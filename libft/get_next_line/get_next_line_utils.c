/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khadj-me <khalilhadjmes1@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:45:26 by khadj-me          #+#    #+#             */
/*   Updated: 2025/02/24 14:07:55 by khadj-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strjoin_plus(const char *s1, const char *s2)
{
	size_t	i;
	char	*result;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	result = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!result)
		return (NULL);
	while (*s1)
		result[i++] = *s1++;
	while (*s2)
		result[i++] = *s2++;
	result[i] = '\0';
	return (result);
}

char	*ft_substr_plus(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*result;

	i = 0;
	if (!s)
		return (NULL);
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	else if (len == ft_strlen(s))
		len = ft_strlen(s) - start;
	if (start > (unsigned)ft_strlen(s))
	{
		result = malloc(1);
		if (!result)
			return (NULL);
		return (result[0] = '\0', result);
	}
	while (len + start > ft_strlen(s))
		len--;
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	while (i < len && s[start])
		result[i++] = s[start++];
	return (result[i] = '\0', result);
}
