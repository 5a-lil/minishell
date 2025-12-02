/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khadj-me <khalilhadjmes1@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 08:44:40 by khadj-me          #+#    #+#             */
/*   Updated: 2024/11/14 14:32:41 by khadj-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
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

//int main(int argc, char **argv)
//{
//	(void)argc;
//	if (argc < 4)
//		return (0);
//	printf("output : %s\n", ft_substr(argv[1], atoi(argv[2]), atoi(argv[3])));
//}