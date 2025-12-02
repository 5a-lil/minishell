/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khadj-me <khalilhadjmes1@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:30:00 by khadj-me          #+#    #+#             */
/*   Updated: 2024/11/14 14:33:06 by khadj-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_str(const char *big, const char *little, int i, int len)
{
	size_t	j;

	j = 0;
	while (big[i] && big[i++] == little[j++] && len > 0)
	{
		if (j == ft_strlen(little))
			return (1);
		len--;
	}
	return (0);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;

	i = 0;
	if ((int)len < 0)
		len = ft_strlen(big);
	if (little[0] == '\0')
		return ((char *)big);
	if (big[0] == '\0' && little[0] == '\0')
		return ((char *)big);
	if (big[0] == '\0')
		return (NULL);
	if (little[0] == '\0')
		return (NULL);
	while (big[i] && len > 0)
	{
		if (check_str(big, little, i, len) == 1)
			return ((char *)&big[i]);
		i++;
		len--;
	}
	return (NULL);
}

//int main(int argc, char **argv)
//{
//	(void)argc;
//	if (argc < 4)
//		return (0);
//	printf("expected : %s\n", strnstr(argv[1], argv[2], atoi(argv[3])));
//	printf("output : %s\n", ft_strnstr(argv[1], argv[2], atoi(argv[3])));
//}