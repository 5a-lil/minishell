/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_wredir_inits.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khadj-me <khalilhadjmes1@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 12:05:50 by dangtran          #+#    #+#             */
/*   Updated: 2025/03/20 12:11:22 by khadj-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	skip_redir_and_quotes(const char *prompt, int *i)
{
	*i += strlen_till_not_char(&prompt[*i], "<>");
	*i += strlen_till_not_char(&prompt[*i], " ");
	*i += strlen_till_char(&prompt[*i], "\'\"<> ");
	while (prompt[*i] && (prompt[*i] == '\"' || prompt[*i] == '\''))
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
	}
	*i += strlen_till_not_char(&prompt[*i], " ");
}

static void	process_prompt_without_redir(const char *prompt, char **temp,
		int *i, t_list **result)
{
	while (prompt[*i])
	{
		if (prompt[*i] && is_in_charset(prompt[*i], "<>") == 0)
		{
			while (prompt[*i] == ' ')
				(*i)++;
			handle_non_quotes_without_redir(prompt, temp, i);
			while (prompt[*i] == ' ')
				(*i)++;
			if (*temp)
				ft_lstadd_back(result, ft_lstnew(ft_strdup(*temp)));
			free(*temp);
			*temp = NULL;
		}
		else
			skip_redir_and_quotes(prompt, i);
	}
}

t_list	*init_without_redir_list(const char *prompt)
{
	int		i;
	char	*temp;
	t_list	*result;

	i = 0;
	temp = NULL;
	result = NULL;
	if (!prompt)
		return (NULL);
	process_prompt_without_redir(prompt, &temp, &i, &result);
	return (result);
}

/* static void	process_prompt_without_redir(const char *prompt, char **temp,
		int *i, t_list **result)
{
	int		i;
	char	*temp;
	t_list	*result;
	int		i;
	char	*temp;
	char	*result;

	while (prompt[*i])
	{
		if (prompt[*i] && is_in_charset(prompt[*i], "<>") == 0)
		{
			while (prompt[*i] == ' ')
				(*i)++;
			handle_non_quotes_without_redir(prompt, temp, i);
			while (prompt[*i] == ' ')
				(*i)++;
			if (*temp)
				ft_lstadd_back(result, ft_lstnew(ft_strdup(*temp)));
			free(*temp);
			*temp = NULL;
		}
		else
		{
			*i += strlen_till_not_char(&prompt[*i], "<>");
			*i += strlen_till_not_char(&prompt[*i], " ");
			*i += strlen_till_char(&prompt[*i], "\'\"<> ");
			while (prompt[*i] && (prompt[*i] == '\"' || prompt[*i] == '\''))
			{
				if (prompt[*i] && prompt[*i] == '\"')
				{
					while (prompt[*i] && prompt[*i] == '\"')
					{
						(*i)++;
						while (prompt[*i] && prompt[*i] != '\"')
							(*i)++;
						if (prompt[*i])
							(*i)++;
					}
				}
				else if (prompt[*i] && prompt[*i] == '\'')
				{
					while (prompt[*i] && prompt[*i] == '\'')
					{
						(*i)++;
						while (prompt[*i] && prompt[*i] != '\'')
							(*i)++;
						if (prompt[*i])
							(*i)++;
					}
				}
			}
			*i += strlen_till_not_char(&prompt[*i], " ");
		}
	}
} */
