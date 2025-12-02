/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khadj-me <khalilhadjmes1@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 11:35:34 by khadj-me          #+#    #+#             */
/*   Updated: 2025/03/22 07:40:58 by khadj-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ctrl_c_display(int i)
{
	(void)i;
	g_sig = 130;
	if (file_exists(".heredoc.tmp") == 1)
		unlink(".heredoc.tmp");
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	ctrl_c_no_display(int i)
{
	(void)i;
	g_sig = 130;
	if (file_exists(".heredoc.tmp") == 1)
		unlink(".heredoc.tmp");
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
}

void	ctrl_c_heredoc(int i)
{
	(void)i;
	close(STDIN_FILENO);
	g_sig = 130;
}
