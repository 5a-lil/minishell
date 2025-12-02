/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khadj-me <khalilhadjmes1@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 09:22:30 by khadj-me          #+#    #+#             */
/*   Updated: 2025/03/22 08:01:26 by khadj-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		g_sig = 0;

t_list	*init_lists(char **to_tokenize)
{
	int		i;
	t_list	*result;
	t_list	*temp;

	i = -1;
	result = NULL;
	temp = NULL;
	while (to_tokenize && to_tokenize[++i])
	{
		temp = ft_lstnew((void *)ft_strdup(to_tokenize[i]));
		if (!temp)
		{
			ft_lstclear(&result, &free);
			exit(EXIT_FAILURE);
		}
		ft_lstadd_back(&result, temp);
	}
	if (!result)
		return (NULL);
	return (result);
}

void	setup_environment(t_data *data, char **envp)
{
	getcwd(data->previous_cwd, PATH_MAX);
	data->exit_code = 0;
	data->child_exit_code = 0;
	data->env_vars = init_lists(envp);
	data->stds[0] = dup(0);
	data->stds[1] = dup(1);
	data->stdin_copy = dup(0);
	data->prompt = NULL;
	data->envp = envp;
	data->end_tty = 0;
	signal(SIGINT, &ctrl_c_display);
	signal(SIGQUIT, SIG_IGN);
}

void	process_line(char *line, t_data *data)
{
	if (line && line[0])
		add_history(line);
	else if (!line)
		return ;
	data->prompt = env_expansion(data, data->prompt);
	prompt_parsing(data->prompt, data);
	free(data->prompt);
	data->prompt = NULL;
}

int	main(int argc, char **argv, char **envp)
{
	t_data	data;

	(void)argc;
	(void)argv;
	if (isatty(STDIN_FILENO) == 0 || isatty(STDOUT_FILENO) == 0)
		return (ft_putendl_fd("Do not pipe minishell, 💗", 2), 1);
	setup_environment(&data, envp);
	data.prompt = readline("🥊🏆 >$ ");
	while (data.end_tty != 1 && data.prompt != NULL)
	{
		process_line(data.prompt, &data);
		if (data.end_tty != 1)
			data.prompt = readline("🥊🏆 >$ ");
	}
	if (data.end_tty != 1)
		printf("exit\n");
	free_data(&data);
	rl_clear_history();
	return (data.exit_code);
}
