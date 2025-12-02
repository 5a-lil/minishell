/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_alph_sorted.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangtran <dangtran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 10:45:48 by khadj-me          #+#    #+#             */
/*   Updated: 2025/03/16 10:12:24 by dangtran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	swap_table(char **a, char **b)
{
	char	*temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	ft_strcmp(const char *a, const char *b)
{
	while (*a && *a == *b)
	{
		++a;
		++b;
	}
	return ((int)(unsigned char)(*a) - (int)(unsigned char)(*b));
}

void	print_export_list(int argc, char **argv)
{
	int	i;
	int	j;

	if (!argv || !argv[0])
		return ;
	i = 0;
	j = 0;
	while (i < argc)
	{
		j = 1;
		while (j < argc - 1)
		{
			if (ft_strcmp(argv[j], argv[j + 1]) > 0)
				swap_table(&argv[j], &argv[j + 1]);
			j++;
		}
		i++;
	}
	j = 1;
	while (j < argc)
	{
		ft_putstr_fd("declare -x ", 1);
		ft_putendl_fd(argv[j], 1);
		j++;
	}
}
