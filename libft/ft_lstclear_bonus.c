/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khadj-me <khalilhadjmes1@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 09:54:35 by khadj-me          #+#    #+#             */
/*   Updated: 2025/01/04 11:46:27 by khadj-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*save;

	while ((*lst) != NULL)
	{
		save = *lst;
		*lst = (*lst)->next;
		ft_lstdelone(save, del);
	}
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

// 	test = ft_lstnew(malloc(1));

// 	ft_lstadd_front(&test, ft_lstnew(malloc(1)));
// 	ft_lstadd_front(&test, ft_lstnew(malloc(1)));
// 	ft_lstadd_front(&test, ft_lstnew(malloc(1)));
// 	ft_lstadd_front(&test, ft_lstnew(malloc(1)));
// 	printf("before clear : \n");
// 	print_list(test);
// 	ft_lstclear(&test, free);
// 	printf("after clear : \n");
// 	print_list(test);
// }