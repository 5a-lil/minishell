/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangtran <dangtran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 10:51:54 by khadj-me          #+#    #+#             */
/*   Updated: 2025/03/20 08:42:23 by dangtran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_valid(const char *token)
{
	int	i;

	i = 0;
	if (!token)
		return (1);
	else if (is_number(token) == 1)
		return (0);
	while (token[i])
	{
		if (i == 0 && (token[i] == '=' || token[i] == '?'))
			return (0);
		else if (is_in_charset(token[i], "-+/") == 1)
			return (0);
		else if (token[i] == '=')
			return (1);
		i++;
	}
	return (1);
}

void	print_env_export(t_list *env_vars)
{
	t_list	*curr;

	curr = env_vars;
	while (curr != NULL)
	{
		printf("declare -x ");
		printf("%s\n", (char *)curr->content);
		curr = curr->next;
	}
}

static void	handle_export_tokens(t_list **tokens, t_list *env_vars)
{
	t_list	*temp_var;
	char	*temp_name;

	while ((*tokens) != NULL && is_in_charset(((char *)(*tokens)->content)[0],
			"|<>") == 0)
	{
		if (ft_strchr((char *)(*tokens)->content, '=') != NULL)
		{
			temp_name = ft_substr((char *)(*tokens)->content, 0,
					strlen_till_char((char *)(*tokens)->content, "="));
			temp_var = find_env_var(env_vars, temp_name);
			if (temp_var != NULL)
				temp_var->content = free_and_replace((char *)temp_var->content,
						ft_strdup((char *)(*tokens)->content));
			else
				ft_lstadd_back(&env_vars,
					ft_lstnew((void *)ft_strdup((char *)(*tokens)->content)));
			free(temp_name);
		}
		(*tokens) = (*tokens)->next;
	}
}

void	export(t_list **tokens, t_list *env_vars, t_data *data)
{
	char	**temp;

	temp = list_to_table(env_vars);
	if (!temp || !temp[0])
		return ;
	if ((*tokens)->next == NULL)
	{
		print_export_list(table_of_table_len(temp), temp);
		(*tokens) = (*tokens)->next;
	}
	else if ((*tokens)->next != NULL
		&& is_valid((char *)(*tokens)->next->content) == 0)
	{
		(*tokens) = (*tokens)->next;
		ft_putendl_fd(" not a valid identifier", 2);
		data->exit_code = 1;
	}
	else
	{
		handle_export_tokens(tokens, env_vars);
	}
	free_char_char(temp);
}
