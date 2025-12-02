/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khadj-me <khalilhadjmes1@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:14:20 by khadj-me          #+#    #+#             */
/*   Updated: 2025/01/11 11:11:51 by khadj-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 1

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <string.h>

char	*get_next_line(int fd) __attribute__((destructor));
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*line_read(int fd, char *stored);
char	*clean_stor(char *str);
void	*ft_memset(void *pointer, int value, size_t count);
void	*ft_calloc(size_t elementCount, size_t elementSize);
char	*sub_line(char *str);
int		check_buf(const char *str);

#endif