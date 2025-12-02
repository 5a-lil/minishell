/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khadj-me <khalilhadjmes1@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:29:19 by khadj-me          #+#    #+#             */
/*   Updated: 2024/11/14 14:33:25 by khadj-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*result;

	i = 0;
	result = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!result)
		return (NULL);
	while (s[i])
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}

//char	ft_toupper_ex(unsigned int i, char c)
//{
//	if (c >= 'a' && c <= 'z')
//		return (c - 32);
//	else
//		return (c);
//}
//
//int	main(int argc, char **argv)
//{
//	char *test;
//	char *result;
//
//	if (argc < 2)
//		return (0);
//	test = argv[1];
//	printf("output before : %s\n", test);
//	result = ft_strmapi(test, ft_toupper_ex);
//	printf("output after : %s\n", result);
//}
