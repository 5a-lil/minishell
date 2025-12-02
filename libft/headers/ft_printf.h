/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khadj-me <khalilhadjmes1@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:14:41 by khadj-me          #+#    #+#             */
/*   Updated: 2025/01/15 08:13:30 by khadj-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include "../libft.h"
# include <limits.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

int		ft_printf(const char *string, ...);
void	putchar_fd(char c, int fd, int *i);
char	*print_nbr(long nb, char *result);
void	putstr_fd(const char *s, int fd, int *i);
char	*print_hexa_upper(unsigned int nb, char *result);
char	*print_hexa_lower(unsigned int nb, char *result);
char	*print_ptr(uintptr_t nb, char *result);
char	*print_unsigned_nbr(unsigned int nb, char *result);
char	*add(char *str, char c);
void	reverse(char *str);
char	*printf_flags(va_list args, const char *string, int *i);
char	*print_char(char c, int *i);
char	*plus_flag(va_list args);
char	*space_flag(va_list args, const char *string, int *i);
char	*hash_flag(va_list args, const char *string);
char	*left_justify(va_list args, const char *string, int *i, int k);
char	*dot_flag(va_list args, const char *string, int *i);
char	*zero_min_field(va_list args, const char *string, int *i);
char	*minimum_field(va_list args, const char *string, int *i);
void	assert(char *res, char *temp, int j);

#endif