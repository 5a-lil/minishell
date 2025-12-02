/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khadj-me <khalilhadjmes1@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 08:56:15 by khadj-me          #+#    #+#             */
/*   Updated: 2025/02/05 09:27:26 by khadj-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_args(char **args, int (*f)(const char *))
{
	int	i;

	i = -1;
	if (!args[0])
		return (0);
	while (args[++i])
		if (f(args[i]) == 0)
			return (0);
	return (1);
}
