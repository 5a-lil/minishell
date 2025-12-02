/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khadj-me <khalilhadjmes1@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 09:26:48 by khadj-me          #+#    #+#             */
/*   Updated: 2024/11/14 14:40:45 by khadj-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*curr;
	int		i;

	curr = lst;
	i = 0;
	while (curr != NULL)
	{
		curr = curr->next;
		i++;
	}
	return (i);
}

//int main(void)
//{
//	t_list * test;
//
//	test = ft_lstnew(malloc(1));
//	ft_lstadd_back(&test, ft_lstnew(malloc(1)));
//	ft_lstadd_back(&test, ft_lstnew(malloc(1)));
//	ft_lstadd_back(&test, ft_lstnew(malloc(1)));
//	ft_lstadd_back(&test, ft_lstnew(malloc(1)));
//	printf("list size : %d\n", ft_lstsize(test));
//}
