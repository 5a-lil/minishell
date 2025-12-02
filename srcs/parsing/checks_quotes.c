/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khadj-me <khalilhadjmes1@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 11:21:51 by dangtran          #+#    #+#             */
/*   Updated: 2025/03/21 08:08:41 by khadj-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_initial_pipe(const char *prompt, t_list **cmd_l)
{
	int	i;

	i = 0;
	while (prompt[i] && prompt[i] == ' ')
		i++;
	if (prompt[i] && prompt[i] == '|')
		return (ft_lstclear(cmd_l, &free),
			ft_putendl_fd(" syntax error near unexpected token `|'", 2), ERROR);
	return (0);
}

static int	check_quotes(const char *prompt, int *i)
{
	if (prompt[*i] == '\"')
	{
		(*i)++;
		while (prompt[*i] && prompt[*i] != '\"')
			(*i)++;
		if (prompt[*i])
			(*i)++;
	}
	else if (prompt[*i] == '\'')
	{
		(*i)++;
		while (prompt[*i] && prompt[*i] != '\'')
			(*i)++;
		if (prompt[*i])
			(*i)++;
	}
	return (0);
}

static int	check_pipes(const char *prompt, int *i, t_list **cmd_l)
{
	if (prompt[*i] == '|')
	{
		(*i)++;
		while (prompt[*i] && prompt[*i] == ' ')
			(*i)++;
		if (!prompt[*i] || prompt[*i] == '|')
			return (ft_lstclear(cmd_l, &free),
				ft_putendl_fd(" syntax error near unexpected token `|'", 2),
				ERROR);
	}
	return (0);
}

int	check_quotes_and_pipes(const char *prompt, t_list **cmd_l)
{
	int	i;

	if (check_initial_pipe(prompt, cmd_l) != 0)
		return (ERROR);
	i = 0;
	while (prompt[i])
	{
		if (prompt[i] == '\"' || prompt[i] == '\'')
			check_quotes(prompt, &i);
		else if (prompt[i] == '|')
		{
			if (check_pipes(prompt, &i, cmd_l) != 0)
				return (ERROR);
		}
		else
			i++;
	}
	return (0);
}
