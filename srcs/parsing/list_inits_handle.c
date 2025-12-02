/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_inits_handle.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangtran <dangtran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 12:07:38 by dangtran          #+#    #+#             */
/*   Updated: 2025/03/20 08:25:13 by dangtran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_double_quotes_list(const char *prompt, char **temp, int *i)
{
	*temp = add(*temp, prompt[(*i)++]);
	if (prompt[*i] && prompt[*i] == '\0')
		return ;
	while (prompt[*i] && prompt[*i] != '\"')
		*temp = add(*temp, prompt[(*i)++]);
	if (prompt[*i])
		*temp = add(*temp, prompt[(*i)++]);
	if (prompt[*i])
		while (prompt[++(*i)] && is_in_charset(prompt[*i], "\"<> ") == 0)
			*temp = add(*temp, prompt[*i]);
}

void	handle_single_quotes_list(const char *prompt, char **temp, int *i)
{
	*temp = add(*temp, prompt[(*i)++]);
	if (prompt[*i] && prompt[*i] == '\0')
		return ;
	while (prompt[*i] && prompt[*i] != '\'')
		*temp = add(*temp, prompt[(*i)++]);
	if (prompt[*i])
		*temp = add(*temp, prompt[(*i)++]);
	if (prompt[*i])
		while (prompt[++(*i)] && is_in_charset(prompt[*i], "\'<> ") == 0)
			*temp = add(*temp, prompt[*i]);
}

void	handle_non_quotes_list(const char *prompt, char **temp, int *i)
{
	while (prompt[*i] && is_in_charset(prompt[*i], "<> ") == 0)
	{
		if (prompt[*i] == '\"')
			handle_double_quotes_list(prompt, temp, i);
		else if (prompt[*i] == '\'')
			handle_single_quotes_list(prompt, temp, i);
		else
			*temp = add(*temp, prompt[(*i)++]);
	}
}

void	handle_special_chars(const char *prompt, char **temp, int *i,
		t_list **result)
{
	*temp = ft_substr(prompt, *i, strlen_till_not_char(&prompt[*i], "<>"));
	if (ft_strlen(*temp) >= 1)
		ft_lstadd_back(result, ft_lstnew(ft_strdup(*temp)));
	free(*temp);
	*temp = NULL;
	*i += strlen_till_not_char(&prompt[*i], "<>");
	while (prompt[*i] && prompt[*i] == ' ')
		(*i)++;
	handle_non_quotes_without_redir(prompt, temp, i);
	while (prompt[*i] && prompt[*i] == ' ')
		(*i)++;
	if (*temp)
		ft_lstadd_back(result, ft_lstnew(ft_strdup(*temp)));
	free(*temp);
	*temp = NULL;
}
