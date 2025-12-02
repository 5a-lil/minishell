/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khadj-me <khalilhadjmes1@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:29:14 by khadj-me          #+#    #+#             */
/*   Updated: 2024/11/14 15:16:14 by khadj-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_recursive_power(int nb, int power)
{
	if (power == 0)
		return (1);
	if (power < 0)
		return (0);
	if (power > 1)
	{
		nb *= ft_recursive_power(nb, power - 1);
	}
	return (nb);
}

static int	count_digits(int n)
{
	int	i;

	i = 1;
	while (n / 10 != 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

static void	int_min(char *result)
{
	result[0] = '-';
	result[1] = '2';
	result[2] = '1';
	result[3] = '4';
	result[4] = '7';
	result[5] = '4';
	result[6] = '8';
	result[7] = '3';
	result[8] = '6';
	result[9] = '4';
	result[10] = '8';
	result[11] = '\0';
}

char	*ft_itoa(int n)
{
	char	*result;
	int		i;
	int		nbdigits;

	i = 0;
	nbdigits = count_digits(n) - 1;
	if (n >= 0)
		result = malloc((nbdigits + 2) * sizeof(char));
	else
		result = malloc((nbdigits + 3) * sizeof(char));
	if (!result)
		return (NULL);
	if (n == -2147483648)
		return (int_min(result), result);
	if (n < 0)
		result[i++] = '-';
	if (n < 0)
		n *= -1;
	while (nbdigits != -1)
		result[i++] = (n / ft_recursive_power(10, nbdigits--)) % 10 + 48;
	result[i] = '\0';
	return (result);
}

// int	main(int argc, char **argv)
// {
// 	(void)argc;
// 	if (argc < 2)
// 		return (0);
// 	printf("output : %s\n", ft_itoa(atoi(argv[1])));
// }