/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khadj-me <khalilhadjmes1@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:24:18 by khadj-me          #+#    #+#             */
/*   Updated: 2025/01/14 08:43:11 by khadj-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	file_check(const char *file)
{
	int	fd;

	fd = open(file, O_RDWR, 0644);
	if (fd == -1)
	{
		close(fd);
		error_handler(NULL);
	}
	close(fd);
}
