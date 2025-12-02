/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_env_expansion.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khadj-me <khalilhadjmes1@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 10:16:02 by dangtran          #+#    #+#             */
/*   Updated: 2025/03/21 14:54:32 by khadj-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	mini_env_expansion_double_quotes(t_data *data, const char *str,
		char **result, int *i)
{
	*result = strjoin_char(*result, str[(*i)++]);
	while (str[*i] && str[*i] != '\"')
	{
		if (str[*i] && str[*i] == '$' && (!str[*i + 1] || is_in_charset(str[*i
						+ 1], " \"") == 1))
		{
			*result = strjoin_char(*result, str[(*i)++]);
			continue ;
		}
		else if (str[*i] && str[*i] == '$' && is_in_charset(str[*i + 1],
				" \0") == 0)
			handle_dollar_sign(data, str, result, i);
		else if (str[*i])
			*result = strjoin_char(*result, str[*i]);
		if (str[*i])
			(*i)++;
	}
	if (str[*i])
		*result = strjoin_char(*result, str[(*i)++]);
}

void	mini_env_expansion(t_data *data, const char *str, char **result, int *i)
{
	if (str[*i] && str[*i] == '$' && (!str[*i + 1] || is_in_charset(str[*i + 1],
				" \"") == 1))
	{
		if (!str[*i + 1] || str[*i + 1] == ' ')
			*result = strjoin_char(*result, str[(*i)++]);
		else if (str[*i + 1] == '\"')
			(*i)++;
	}
	else if (str[*i] && str[*i] == '\'')
		handle_single_quotes(str, result, i);
	else if (str[*i] && str[*i] == '$' && is_in_charset(str[*i + 1],
			" \0") == 0)
		handle_dollar_sign(data, str, result, i);
	else if (str[*i])
		*result = strjoin_char(*result, str[*i]);
	if (str[*i])
		(*i)++;
}
