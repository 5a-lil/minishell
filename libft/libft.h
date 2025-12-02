/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khadj-me <khalilhadjmes1@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:46:02 by khadj-me          #+#    #+#             */
/*   Updated: 2025/03/17 10:24:07 by khadj-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H

# include "./headers/ft_printf.h"
# include "./headers/get_next_line.h"
# include <ctype.h>
# include <errno.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int					ft_isalpha(int character);
int					ft_isdigit(int character);
int					ft_isalnum(int character);
int					ft_isascii(int character);
int					ft_isprint(int character);
size_t				ft_strlen(const char *str);
void				*ft_memset(void *pointer, int value, size_t count);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *destination, const void *source,
						size_t size);
void				*ft_memmove(void *destination, const void *source,
						size_t size);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
int					ft_toupper(int character);
int					ft_tolower(int character);
char				*ft_strchr(const char *s, int searchedChar);
char				*ft_strrchr(const char *string, int searchedChar);
int					ft_strncmp(const char *first, const char *second,
						size_t length);
void				*ft_memchr(const void *memoryBlock, int searchedChar,
						size_t size);
int					ft_memcmp(const void *pointer1, const void *pointer2,
						size_t size);
char				*ft_strnstr(const char *big, const char *little,
						size_t len);
int					ft_atoi(const char *theString);
void				*ft_calloc(size_t elementCount, size_t elementSize);
char				*ft_strdup(const char *source);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char c);
char				*ft_itoa(int n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));
void				free_char_char(char **tofree);
int					is_number(const char *to_check);
char				*is_biggest_str(const char *str1, const char *str2,
						char *charset, int (*f)(const char *, const char *));
void				error_handler(char *error_message);
void				print_table_of_table(char **table);
void				file_check(const char *file);
size_t				table_of_table_len(char **table);
char				**split_and_free(char *to_split, char splitter);
int					is_in_charset(char c, const char *charset);
int					strchr_table(char **table, char to_search);
int					is_positive(const char *nb);
int					check_args(char **args, int (*f)(const char *));
int					strlen_till_char(const char *str, const char *c);
char				*free_and_replace(char *to_free, char *to_replace);

#endif
