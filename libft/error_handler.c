/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khadj-me <khalilhadjmes1@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 12:09:08 by khadj-me          #+#    #+#             */
/*   Updated: 2025/03/17 12:04:35 by khadj-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	error_handler(char *error_message)
{
	if (!error_message)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
	else
		ft_putendl_fd(error_message, 2);
	exit(EXIT_FAILURE);
}
