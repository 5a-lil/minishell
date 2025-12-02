/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_redirs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khadj-me <khalilhadjmes1@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 13:38:20 by dangtran          #+#    #+#             */
/*   Updated: 2025/03/22 07:18:40 by khadj-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	mini_handle_output_redir(t_list **curr, int temp_fds[2])
{
	if (((char *)(*curr)->content)[0] == '>'
		&& ft_strcmp((char *)(*curr)->content, ">>") == 0 && temp_fds[0] != -1
		&& temp_fds[1] != -1)
		handle_output_redir(curr, temp_fds, 1, &open_file);
	else if (((char *)(*curr)->content)[0] == '>' && temp_fds[0] != -1
		&& temp_fds[1] != -1)
		handle_output_redir(curr, temp_fds, 0, &open_file);
}

void	mini_handle_input_redir(t_list **curr, int temp_fds[2], t_data *data)
{
	if (((char *)(*curr)->content)[0] == '<'
		&& ft_strcmp((char *)(*curr)->content, "<<") == 0)
	{
		dup2(data->stds[0], INFILE);
		*curr = (*curr)->next;
		heredoc(data, (char *)(*curr)->content);
	}
	else if (((char *)(*curr)->content)[0] == '<' && temp_fds[0] != -1
		&& temp_fds[1] != -1)
		handle_input_redir(curr, temp_fds, &open_file);
}
