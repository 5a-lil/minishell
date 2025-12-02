/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khadj-me <khalilhadjmes1@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:33:24 by khadj-me          #+#    #+#             */
/*   Updated: 2024/12/02 13:12:59 by khadj-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*printf_opt_flags(va_list args, const char *string, int *i, char **str)
{
	if (*string == ' ')
		*str = space_flag(args, string, i);
	else if (*string == '+')
		*str = plus_flag(args);
	else if (*string == '#')
		*str = hash_flag(args, string);
	else if (*string == '.')
		*str = dot_flag(args, string, i);
	else if (*string == '0')
		*str = zero_min_field(args, string, i);
	else if (*string == '-')
		*str = left_justify(args, string, i, 1);
	else if (ft_isdigit(*string))
		*str = minimum_field(args, string, i);
	else
		return (0);
	return (*str);
}

char	*printf_flags(va_list args, const char *string, int *i)
{
	char	*str;

	str = NULL;
	if (printf_opt_flags(args, string, i, &str) != 0)
		return (str);
	else if (*string == 'c')
		str = print_char(va_arg(args, int), i);
	else if (*string == 's')
		str = ft_strdup(va_arg(args, char *));
	else if (*string == 'd')
		str = print_nbr(va_arg(args, int), str);
	else if (*string == 'p')
		str = print_ptr(va_arg(args, uintptr_t), str);
	else if (*string == 'x')
		str = print_hexa_lower(va_arg(args, uintptr_t), str);
	else if (*string == 'X')
		str = print_hexa_upper(va_arg(args, uintptr_t), str);
	else if (*string == 'i')
		str = print_nbr(va_arg(args, int), str);
	else if (*string == 'u')
		str = print_unsigned_nbr(va_arg(args, int), str);
	else if (*string == '%')
		putchar_fd('%', 1, i);
	return (str);
}

void	check(char *result, int *i)
{
	if (result)
		putstr_fd(result, 1, i);
	free(result);
}

int	ft_printf(const char *string, ...)
{
	int		i;
	char	*result;
	va_list	args;

	if (!string)
		return (-1);
	i = 0;
	va_start(args, string);
	while (*string)
	{
		if (*string == '%')
		{
			string++;
			result = printf_flags(args, string, &i);
			check(result, &i);
			while (ft_isdigit(*string) || *string == '-' || *string == '.'
				|| *string == '#' || *string == ' ' || *string == '+')
				string++;
			string++;
		}
		else
			putchar_fd(*string++, 1, &i);
	}
	va_end(args);
	return (i);
}

// int	main(int argc, char **argv)
// {
// 	(void)argc;
// 	(void)argv;

// 	printf("%d\n", printf(0));
// 	ft_printf("%d\n", ft_printf(0));
// 	return (0);
// }
