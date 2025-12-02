/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khadj-me <khalilhadjmes1@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 14:56:21 by khadj-me          #+#    #+#             */
/*   Updated: 2025/03/21 08:06:26 by khadj-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	handle_dash(t_list **tokens, t_data *data, char *cwd)
{
	(*tokens) = (*tokens)->next;
	if ((*tokens)->next != NULL
		&& is_in_charset(((char *)(*tokens)->next->content)[0], "|<>") == 0)
		return ((*tokens) = (*tokens)->next, data->exit_code = 1,
			ft_putendl_fd(" too many arguments", 2), 1);
	printf("%s\n", data->previous_cwd);
	getcwd(data->previous_cwd, PATH_MAX);
	if (chdir((const char *)cwd) == -1)
		return (data->exit_code = 1, (*tokens) = (*tokens)->next, write(2, " ",
				1), ft_putendl_fd(strerror(errno), 2), errno);
	return (data->exit_code = 0, 0);
}

static int	handle_non_dash(t_list **tokens, t_data *data, t_list *env_vars)
{
	if ((*tokens)->next != NULL && ((char *)(*tokens)->next->content)[0] != '~')
	{
		(*tokens) = (*tokens)->next;
		if ((*tokens)->next != NULL
			&& is_in_charset(((char *)(*tokens)->next->content)[0], "|<>") == 0)
			return ((*tokens) = (*tokens)->next, data->exit_code = 1,
				ft_putendl_fd(" too many arguments", 2), 1);
		if (chdir((const char *)(*tokens)->content) == -1)
			return (data->exit_code = 1, (*tokens) = (*tokens)->next, write(2,
					" ", 1), ft_putendl_fd(strerror(errno), 2), errno);
	}
	else if (env_vars && find_env_var(env_vars, "HOME") != NULL)
	{
		if (chdir(ft_strchr((char *)find_env_var(env_vars, "HOME")->content,
					'=') + 1) == -1)
			return (data->exit_code = 1, (*tokens) = (*tokens)->next, write(2,
					" ", 1), ft_putendl_fd(strerror(errno), 2), errno);
	}
	return (data->exit_code = 0, 0);
}

int	cd(t_list **tokens, t_data *data, t_list *env_vars)
{
	char	*cwd;

	cwd = ft_strdup(data->previous_cwd);
	if ((*tokens)->next != NULL && ((char *)(*tokens)->next->content)[0] == '-'
		&& ft_strlen((char *)(*tokens)->next->content) == 1)
		return (handle_dash(tokens, data, cwd));
	free(cwd);
	getcwd(data->previous_cwd, PATH_MAX);
	if (handle_non_dash(tokens, data, env_vars) != 0)
		return (data->exit_code);
	(*tokens) = (*tokens)->next;
	return (data->exit_code = 0, 0);
}
