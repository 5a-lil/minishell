/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khadj-me <khalilhadjmes1@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 09:44:27 by khadj-me          #+#    #+#             */
/*   Updated: 2024/11/14 15:16:06 by khadj-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*curr;

	curr = *lst;
	if (curr == NULL)
	{
		*lst = new;
		return ;
	}
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = &*new;
}

// void print_list(t_list * head) 
// {
//     t_list * current = head;

//     while (current != NULL) {
//         printf("%p\n", current->content);
//         current = current->next;
//     }
// }

// int main(int argc, char **argv)
// {
// 	t_list * test;
// 	test = NULL;
// 	ft_lstadd_back(&test, ft_lstnew((void *)77));
// 	ft_lstadd_back(&test, ft_lstnew((void *)77));
// 	ft_lstadd_back(&test, ft_lstnew((void *)77));
// 	ft_lstadd_back(&test, ft_lstnew((void *)77));
// 	print_list(test);
// }
