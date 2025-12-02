/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khadj-me <khalilhadjmes1@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 09:33:07 by khadj-me          #+#    #+#             */
/*   Updated: 2025/02/27 12:09:45 by khadj-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	pwd(t_list **tokens)
{
	char	buffer[PATH_MAX];

	if (getcwd(buffer, PATH_MAX) == NULL)
		return ((*tokens) = (*tokens)->next, ft_putendl_fd(strerror(errno), 2),
			errno);
	printf("%s\n", buffer);
	(*tokens) = (*tokens)->next;
	return (0);
}
