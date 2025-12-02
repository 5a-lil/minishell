/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive_descent_pars.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khadj-me <khalilhadjmes1@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 15:51:17 by khadj-me          #+#    #+#             */
/*   Updated: 2025/03/22 07:40:44 by khadj-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_list(t_list *list)
{
	t_list	*curr;

	curr = list;
	while (curr != NULL)
	{
		printf("%s\n", (char *)curr->content);
		curr = curr->next;
	}
}

int	prompt_parsing(char *line, t_data *data)
{
	t_list	*list;
	int		i;
	char	**split;

	if (!line || (int)ft_strlen(line) == strlen_till_not_char(line, " "))
		return (1);
	list = NULL;
	i = 0;
	split = split_ign_quote(line, '|');
	while (split && split[i] != NULL)
		ft_lstadd_back(&list, ft_lstnew((void *)ft_strdup(split[i++])));
	if (split && check_syntax(line) == ERROR)
	{
		ft_lstclear(&list, &free);
		free_char_char(split);
		data->exit_code = 2;
		return (1);
	}
	else if (split && split[0])
		check_list(list, data->env_vars, data);
	if (file_exists(".heredoc.tmp") == 1)
		unlink(".heredoc.tmp");
	ft_lstclear(&list, &free);
	free_char_char(split);
	return (0);
}
