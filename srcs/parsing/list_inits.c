/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_inits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khadj-me <khalilhadjmes1@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 11:42:35 by khadj-me          #+#    #+#             */
/*   Updated: 2025/03/20 08:59:43 by khadj-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	strlen_till_not_char(const char *str, const char *charset)
{
	int	i;

	i = 0;
	while (str[i] && is_in_charset(str[i], charset) == 1)
		i++;
	return (i);
}

static void	process_prompt(const char *prompt, char **temp, int *i,
		t_list **result)
{
	while (prompt[*i])
	{
		if (prompt[*i] && is_in_charset(prompt[*i], "<>") == 0)
		{
			while (prompt[*i] && prompt[*i] == ' ')
				(*i)++;
			if (prompt[*i] != '\0')
				handle_non_quotes_list(prompt, temp, i);
			while (prompt[*i] && prompt[*i] == ' ')
				(*i)++;
			if (*temp)
				ft_lstadd_back(result, ft_lstnew(ft_strdup(*temp)));
			free(*temp);
			*temp = NULL;
		}
		else
			handle_special_chars(prompt, temp, i, result);
	}
}

t_list	*init_prompt_list(const char *prompt)
{
	int		i;
	char	*temp;
	t_list	*result;

	i = 0;
	temp = NULL;
	result = NULL;
	if (!prompt)
		return (NULL);
	process_prompt(prompt, &temp, &i, &result);
	return (result);
}
