/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khadj-me <khalilhadjmes1@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 09:19:38 by khadj-me          #+#    #+#             */
/*   Updated: 2024/11/14 15:15:49 by khadj-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
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
// 	ft_lstadd_front(&test, ft_lstnew((void *)77));
// 	ft_lstadd_front(&test, ft_lstnew((void *)77));
// 	ft_lstadd_front(&test, ft_lstnew((void *)77));
// 	ft_lstadd_front(&test, ft_lstnew((void *)77));
// 	print_list(test);
// }