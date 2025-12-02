/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khadj-me <khalilhadjmes1@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:13:13 by khadj-me          #+#    #+#             */
/*   Updated: 2025/02/24 14:07:50 by khadj-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	check_buf(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		if (str[i++] == '\n')
			return (1);
	return (0);
}

char	*sub_line(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		if (str[i] == '\n')
			return (ft_substr(str, 0, i + 1));
		i++;
		if (i == ft_strlen(str))
			return (ft_substr(str, 0, i));
	}
	return (NULL);
}

char	*clean_stor(char *str)
{
	char	*result;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!str)
		return (free(str), NULL);
	while (str[i])
	{
		if (str[i] == '\n')
		{
			result = ft_calloc(ft_strlen(&str[i + 1]) + 1, 1);
			i++;
			while (str[i] != '\0')
				result[j++] = str[i++];
			result[j] = '\0';
			free(str);
			return (result);
		}
		i++;
	}
	return (free(str), NULL);
}

char	*line_read(int fd, char *stored)
{
	int		i;
	char	*temp;
	char	*buf;

	buf = ft_calloc(BUFFER_SIZE + 1, 1);
	if (!stored)
		stored = ft_calloc(1, 1);
	buf[BUFFER_SIZE] = '\0';
	i = read(fd, buf, BUFFER_SIZE);
	while (i > 0)
	{
		buf[i] = '\0';
		temp = ft_strjoin(stored, buf);
		if (!temp)
			return (NULL);
		free(stored);
		stored = temp;
		if (check_buf(stored) == 1)
			break ;
		i = read(fd, buf, BUFFER_SIZE);
	}
	free(buf);
	return (stored);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stored;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (free(stored), stored = NULL, NULL);
	stored = line_read(fd, stored);
	if (!stored)
		return (free(stored), NULL);
	line = sub_line(stored);
	stored = clean_stor(stored);
	return (line);
}

/*int	main(int argc, char **argv)
{
	(void)argc;
	int i;
	int fd;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	while (i++ < atoi(argv[2]))
		printf("LINE : %s", get_next_line(fd));

	close (fd);

	return (0);
}*/