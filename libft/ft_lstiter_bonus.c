/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khadj-me <khalilhadjmes1@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 10:42:08 by khadj-me          #+#    #+#             */
/*   Updated: 2024/12/10 14:22:51 by khadj-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*curr;

	if (!lst)
		return ;
	curr = lst;
	while (curr->next != NULL)
	{
		f(curr->content);
		curr = curr->next;
	}
	f(curr->content);
}

//void add_one(void * p) 
//{
//	++*(int*)p;
//}
//
//int main(void)
//{
//	int i;
//	t_list * test;
//
//	i = 76;
//	test = ft_lstnew(&i);
//	printf("before iter : %d\n", *(int *)test->content);
//	ft_lstiter(test, add_one);
//	printf("after iter : %d\n", *(int *)test->content);
//}