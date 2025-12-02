/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khadj-me <khalilhadjmes1@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 11:45:28 by khadj-me          #+#    #+#             */
/*   Updated: 2025/03/21 08:17:05 by khadj-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	handle_redirection_error(t_list **cmd_l)
{
	ft_lstclear(cmd_l, &free);
	ft_putendl_fd(" syntax error", 2);
	return (ERROR);
}

static int	check_redirection_syntax(t_list **curr, t_list **cmd_l)
{
	if (((char *)(*curr)->content)[0] == '<'
		&& ((char *)(*curr)->content)[1] == '>')
		return (handle_redirection_error(cmd_l));
	else if (((char *)(*curr)->content)[0] == '>'
		&& ((char *)(*curr)->content)[1] == '<')
		return (handle_redirection_error(cmd_l));
	else if ((*curr)->next && ((char *)(*curr)->next->content)[0] == '|')
		return (handle_redirection_error(cmd_l));
	else if (!(*curr)->next)
		return (handle_redirection_error(cmd_l));
	if (ft_strlen((char *)(*curr)->content) > 2)
		return (handle_redirection_error(cmd_l));
	(*curr) = (*curr)->next;
	if (!(*curr) || is_in_charset(((char *)(*curr)->content)[0], "<>") == 1)
		return (handle_redirection_error(cmd_l));
	return (0);
}

static int	check_redirections(t_list *curr, t_list **cmd_l)
{
	while (curr)
	{
		if (is_in_charset(((char *)curr->content)[0], "<>") == 1)
		{
			if (check_redirection_syntax(&curr, cmd_l) != 0)
				return (ERROR);
		}
		else
			curr = curr->next;
	}
	return (0);
}

int	check_syntax(const char *prompt)
{
	t_list	*cmd_l;
	t_list	*curr;

	if (!prompt)
		return (0);
	cmd_l = init_prompt_list(prompt);
	if (!cmd_l)
		return (0);
	if (check_quotes_and_pipes(prompt, &cmd_l) != 0)
		return (ERROR);
	curr = cmd_l;
	if (check_redirections(curr, &cmd_l) != 0)
		return (ERROR);
	ft_lstclear(&cmd_l, &free);
	return (0);
}
