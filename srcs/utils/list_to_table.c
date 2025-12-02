/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_to_table.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khadj-me <khalilhadjmes1@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:04:31 by khadj-me          #+#    #+#             */
/*   Updated: 2025/02/27 08:45:15 by khadj-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**list_to_table(t_list *list)
{
	int		i;
	t_list	*curr;
	char	**result;

	i = 0;
	curr = list;
	result = malloc((ft_lstsize(list) + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	while (curr != NULL)
	{
		result[i++] = ft_strdup((char *)curr->content);
		curr = curr->next;
	}
	result[i] = NULL;
	return (result);
}
