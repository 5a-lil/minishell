/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_expansion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khadj-me <khalilhadjmes1@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 09:43:35 by khadj-me          #+#    #+#             */
/*   Updated: 2025/03/21 17:25:27 by khadj-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*strjoin_char(char *str, char c)
{
	int		i;
	char	*result;

	i = 0;
	result = malloc(ft_strlen(str) + 2);
	if (!result)
		return (NULL);
	while (str && str[i])
	{
		result[i] = str[i];
		i++;
	}
	result[i++] = c;
	result[i] = '\0';
	return (free(str), result);
}

void	dollar_err_code(char **result, int *i, t_data *data)
{
	char	*temp;
	char	*temp_to_free;

	temp = NULL;
	temp_to_free = NULL;
	(*i)++;
	if (g_sig != 0)
		temp = ft_itoa(g_sig);
	else
		temp = ft_itoa(data->exit_code);
	temp_to_free = *result;
	*result = ft_strjoin(*result, temp);
	free(temp);
	temp = NULL;
	free(temp_to_free);
	temp_to_free = NULL;
}

void	handle_single_quotes(const char *str, char **result, int *i)
{
	*result = strjoin_char(*result, str[(*i)++]);
	while (str[*i] && str[*i] != '\'')
		*result = strjoin_char(*result, str[(*i)++]);
	if (str[*i])
		*result = strjoin_char(*result, str[*i]);
}

void	handle_dollar_sign(t_data *data, const char *str, char **result,
		int *i)
{
	char	*temp;
	char	*temp_to_free;
	t_list	*env_var;

	if (str[*i + 1] && str[*i + 1] == '?')
	{
		dollar_err_code(result, i, data);
		return ;
	}
	temp = ft_substr(&str[*i], 0, strlen_till_char((const char *)&str[*i + 1],
				" $\"\'") + 1);
	if (!temp)
		return ;
	*i += strlen_till_char((const char *)&str[*i + 1], " $\"\'");
	env_var = find_env_var(data->env_vars, temp + 1);
	if (env_var)
	{
		temp_to_free = *result;
		*result = ft_strjoin(*result, ft_strchr((const char *)env_var->content,
					'=') + 1);
		free(temp_to_free);
	}
	free(temp);
}

char	*env_expansion(t_data *data, char *str)
{
	char	*result;
	int		i;

	result = NULL;
	i = 0;
	if (ft_strlen(str) == 0)
		return (str);
	while (str[i])
	{
		if (str[i] && str[i] == '\"')
			mini_env_expansion_double_quotes(data, str, &result, &i);
		else
			mini_env_expansion(data, str, &result, &i);
	}
	free(str);
	return (result);
}

/*
char	*env_expansion(t_data *data, char *str)
{
	char	*result;
	int		i;

	result = NULL;
	i = 0;
	if (ft_strlen(str) == 0)
		return (str);
	while (str[i])
	{
		if (str[i] && str[i] == '\"')
		{
			result = strjoin_char(result, str[i++]);
			while (str[i] && str[i] != '\"')
			{
				if (str[i] && str[i] == '$' && (!str[i + 1]
						|| is_in_charset(str[i + 1], " \"") == 1))
				{
					if (!str[i + 1] || str[i + 1] == ' ')
						result = strjoin_char(result, str[i++]);
					else if (str[i + 1] == '\"')
						i++;
					continue ;
				}
				else if (str[i] && str[i] == '$' && is_in_charset(str[i + 1],
						" \0") == 0)
					handle_dollar_sign(data, str, &result, &i);
				else if (str[i])
					result = strjoin_char(result, str[i]);
				if (str[i])
					i++;
			}
			if (str[i])
				result = strjoin_char(result, str[i++]);
		}
		else
		{
			if (str[i] && str[i] == '$' && (!str[i + 1] || is_in_charset(str[i
							+ 1], " \"") == 1))
			{
				if (!str[i + 1] || str[i + 1] == ' ')
					result = strjoin_char(result, str[i++]);
				else if (str[i + 1] == '\"')
					i++;
				continue ;
			}
			else if (str[i] && str[i] == '\'')
				handle_single_quotes(str, &result, &i);
			else if (str[i] && str[i] == '$' && is_in_charset(str[i + 1],
					" \0") == 0)
				handle_dollar_sign(data, str, &result, &i);
			else if (str[i])
				result = strjoin_char(result, str[i]);
			if (str[i])
				i++;
		}
	}
	free(str);
	return (result);
}
	*/
