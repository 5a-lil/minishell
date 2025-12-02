/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khadj-me <khalilhadjmes1@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:18:43 by khadj-me          #+#    #+#             */
/*   Updated: 2025/03/13 08:15:16 by khadj-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *source)
{
	size_t	i;
	char	*result;

	if (!source)
		return (ft_strdup("(null)"));
	i = 0;
	result = malloc(ft_strlen(source) * sizeof(char) + 1);
	if (!result)
		return (NULL);
	while (*source)
		result[i++] = *source++;
	result[i] = '\0';
	return (result);
}

//int main(int argc, char **argv)
//{
//	(void)argc;
//	char * test;
//	if (argc < 2)
//		return (0);
//	
//	test = ft_strdup(argv[1]);
//	printf("output : %s\n", test);
//}
