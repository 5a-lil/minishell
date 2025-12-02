/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangtran <dangtran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:54:41 by khadj-me          #+#    #+#             */
/*   Updated: 2025/03/20 08:43:46 by dangtran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	del_env_var(t_list **lst, char *content)
{
	t_list	*save;
	t_list	*curr;

	curr = *lst;
	while (curr->next != NULL)
	{
		save = curr->next;
		if (ft_strncmp((char *)curr->next->content, content,
				strlen_till_char(is_biggest_str(
						(const char *)curr->next->content,
						(const char *)content, "=", &strlen_till_char),
					"=")) == 0)
		{
			curr->next = save->next;
			ft_lstdelone(save, free);
			return ;
		}
		curr = curr->next;
	}
}

void	unset(t_list **tokens, t_list *env_vars)
{
	t_list	*curr_env_var;

	curr_env_var = env_vars;
	if ((*tokens)->next == NULL
		|| is_in_charset(((char *)(*tokens)->next->content)[0], "|<>") == 1)
		(*tokens) = (*tokens)->next;
	else
	{
		(*tokens) = (*tokens)->next;
		while ((*tokens) != NULL
			&& is_in_charset(((char *)(*tokens)->content)[0], "|<>") == 0)
		{
			if (ft_strchr((const char *)(*tokens)->content, '=') != NULL)
				printf(" not a valid identifier\n");
			if (env_vars)
				del_env_var(&env_vars, (char *)(*tokens)->content);
			(*tokens) = (*tokens)->next;
		}
	}
}
