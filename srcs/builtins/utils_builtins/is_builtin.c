/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khadj-me <khalilhadjmes1@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 20:32:55 by khadj-me          #+#    #+#             */
/*   Updated: 2025/03/18 16:56:10 by khadj-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	strcmp_skip_space(const char *a, const char *b)
{
	while (*a && *a == ' ')
		a++;
	while (*a && *a == *b)
	{
		++a;
		++b;
	}
	return ((int)(unsigned char)(*a) - (int)(unsigned char)(*b));
}

int	is_builtin(const char *cmd)
{
	char	*temp;

	temp = ft_substr(cmd, strlen_till_not_char(cmd, " "),
			strlen_till_char(&cmd[strlen_till_not_char(cmd, " ")], " "));
	if (!temp || !cmd)
		return (0);
	if (strcmp_skip_space(temp, "echo") == 0)
		return (free(temp), 1);
	else if (strcmp_skip_space(temp, "cd") == 0)
		return (free(temp), 1);
	else if (strcmp_skip_space(temp, "env") == 0)
		return (free(temp), 1);
	else if (strcmp_skip_space(temp, "exit") == 0)
		return (free(temp), 1);
	else if (strcmp_skip_space(temp, "export") == 0)
		return (free(temp), 1);
	else if (strcmp_skip_space(temp, "pwd") == 0)
		return (free(temp), 1);
	else if (strcmp_skip_space(temp, "unset") == 0)
		return (free(temp), 1);
	else if (is_in_charset(temp[0], "./") == 1 && is_executable(temp) == FALSE)
		return (free(temp), 1);
	else
		return (free(temp), 0);
}
