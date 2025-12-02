/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khadj-me <khalilhadjmes1@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:02:36 by khadj-me          #+#    #+#             */
/*   Updated: 2024/11/14 14:32:57 by khadj-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *string, int searchedChar)
{
	size_t	i;

	i = ft_strlen(string);
	while ((signed)i >= 0)
	{
		if (string[i] == (char)searchedChar)
			return ((char *)&string[i]);
		i--;
	}
	return (NULL);
}

//int main(int argc, char **argv)
//{
//	(void)argc;
//	if (argc < 3)
//		return (0);
//	printf("expected : %s\n", strrchr(argv[1], argv[2][0]));
//	printf("output : %s\n", ft_strrchr(argv[1], argv[2][0]));
//}