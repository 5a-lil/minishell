/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtins.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khadj-me <khalilhadjmes1@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 11:59:36 by dangtran          #+#    #+#             */
/*   Updated: 2025/03/21 08:41:26 by khadj-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*my_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (s[i] == (char)c)
		return ((char *)s);
	return (NULL);
}

char	*find_valid_path(t_list *env_vars, char **cmd)
{
	t_list	*curr;
	char	**paths;
	char	*path;
	char	*path_w_cmd;
	int		i;

	curr = env_vars;
	path = NULL;
	i = 0;
	while (curr && ft_strncmp((char *)curr->content, "PATH", 4) != 0)
		curr = curr->next;
	if (curr)
		path = my_strchr((char *)curr->content, ':');
	paths = split_quote(path, ':');
	i = 0;
	while (paths && paths[i])
	{
		path = ft_strjoin(paths[i++], "/");
		path_w_cmd = ft_strjoin(path, cmd[0]);
		if (access(path_w_cmd, F_OK | X_OK) == 0)
			return (free(path), free_char_char(paths), path_w_cmd);
		free(path);
		free(path_w_cmd);
	}
	return (free_char_char(paths), ft_strdup(cmd[0]));
}

static void	exec_builtin_command(t_list **curr, t_list *env_vars, t_data *data)
{
	if (ft_strncmp((char *)(*curr)->content, "echo",
		ft_strlen((char *)(*curr)->content)) == 0)
		echo(curr);
	else if (ft_strncmp((char *)(*curr)->content, "cd",
		ft_strlen((char *)(*curr)->content)) == 0)
		cd(curr, data, env_vars);
	else if (ft_strncmp((char *)(*curr)->content, "pwd",
		ft_strlen((char *)(*curr)->content)) == 0)
		pwd(curr);
	else if (ft_strncmp((char *)(*curr)->content, "exit",
		ft_strlen((char *)(*curr)->content)) == 0)
		exit_bash(curr, data);
	else if (ft_strncmp((char *)(*curr)->content, "env",
		ft_strlen((char *)(*curr)->content)) == 0)
		env(curr, env_vars);
	else if (ft_strncmp((char *)(*curr)->content, "export",
		ft_strlen((char *)(*curr)->content)) == 0)
		export(curr, env_vars, data);
	else if (ft_strncmp((char *)(*curr)->content, "unset",
		ft_strlen((char *)(*curr)->content)) == 0)
		unset(curr, env_vars);
	else if (is_in_charset(((char *)(*curr)->content)[0], "./") == 1
		&& is_executable((char *)(*curr)->content) == FALSE)
		is_dir(curr, data);
}

void	exec_builtins(char *temp_cmd, t_list *env_vars, t_data *data)
{
	t_list	*cmd_l;
	t_list	*curr;

	if (!temp_cmd)
		return ;
	cmd_l = init_without_redir_list(temp_cmd);
	if (!cmd_l)
		return (free(temp_cmd));
	curr = cmd_l;
	free(temp_cmd);
	exec_builtin_command(&curr, env_vars, data);
	ft_lstclear(&cmd_l, &free);
}
