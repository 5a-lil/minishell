/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_env_var.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khadj-me <khalilhadjmes1@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 10:12:14 by khadj-me          #+#    #+#             */
/*   Updated: 2025/02/27 12:08:32 by khadj-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*find_env_var(t_list *env_vars, char *var_name)
{
	t_list	*curr;
	char	*temp;

	curr = env_vars;
	temp = NULL;
	while (curr != NULL)
	{
		temp = ft_substr((char *)curr->content, 0,
				strlen_till_char((char *)curr->content, "="));
		if (ft_strncmp(temp, var_name, ft_strlen(is_biggest_str(temp, var_name,
						"\0", &strlen_till_char))) == 0)
			return (free(temp), curr);
		free(temp);
		curr = curr->next;
	}
	return (NULL);
}
