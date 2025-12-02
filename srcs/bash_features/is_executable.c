/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_executable.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khadj-me <khalilhadjmes1@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 10:39:14 by khadj-me          #+#    #+#             */
/*   Updated: 2025/03/21 07:55:23 by khadj-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	file_exists(const char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	close(fd);
	return (1);
}

static int	is_binary_executable(const char *path)
{
	int		file;
	char	buf[4];
	ssize_t	n;

	file = open(path, O_RDONLY, 0644);
	if (file == -1)
		return (ERROR);
	ft_memset(buf, 0, 4);
	n = read(file, buf, sizeof(buf));
	close(file);
	return (ft_memcmp(buf,
			"\x7f"
			"ELF",
			4));
}

static int	is_shell_script(const char *path)
{
	int		file;
	char	shebang[3];

	file = open(path, O_RDONLY, 0644);
	if (file == -1)
		return (ERROR);
	ft_memset(shebang, 0, 3);
	read(file, shebang, sizeof(shebang));
	shebang[2] = '\0';
	close(file);
	return (ft_strcmp(shebang, "#!"));
}

int	is_executable(const char *path)
{
	if (access(path, X_OK) != 0)
		return (FALSE);
	if (is_binary_executable(path) == 0)
		return (TRUE);
	else if (is_shell_script(path) == 0)
		return (TRUE);
	return (0);
}
