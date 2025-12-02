/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_wredir_inits_handle.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khadj-me <khalilhadjmes1@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 09:53:21 by dangtran          #+#    #+#             */
/*   Updated: 2025/03/20 12:25:42 by khadj-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_double_quotes_without_redir(const char *prompt, char **temp,
		int *i)
{
	(*i)++;
	if (prompt[*i] == '\0')
		return ;
	while (prompt[*i] && prompt[*i] != '\"')
		*temp = add(*temp, prompt[(*i)++]);
	if (prompt[*i])
		while (prompt[++(*i)] && is_in_charset(prompt[*i], "\"<> ") == 0)
			*temp = add(*temp, prompt[*i]);
}

void	handle_single_quotes_without_redir(const char *prompt, char **temp,
		int *i)
{
	(*i)++;
	if (prompt[*i] == '\0')
		return ;
	while (prompt[*i] && prompt[*i] != '\'')
		*temp = add(*temp, prompt[(*i)++]);
	if (prompt[*i])
		while (prompt[++(*i)] && is_in_charset(prompt[*i], "\'<> ") == 0)
			*temp = add(*temp, prompt[*i]);
}

void	handle_non_quotes_without_redir(const char *prompt, char **temp, int *i)
{
	while (prompt[*i] && is_in_charset(prompt[*i], "<> ") == 0)
	{
		if (prompt[*i] == '\"')
			handle_double_quotes_without_redir(prompt, temp, i);
		else if (prompt[*i] == '\'')
			handle_single_quotes_without_redir(prompt, temp, i);
		else
			*temp = add(*temp, prompt[(*i)++]);
	}
}
