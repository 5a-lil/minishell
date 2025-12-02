/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khadj-me <khalilhadjmes1@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 09:48:59 by khadj-me          #+#    #+#             */
/*   Updated: 2024/11/14 14:41:47 by khadj-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}

//void print_list(t_list * head) 
//{
//    t_list * current = head;
//
//    while (current != NULL) {
//        printf("%p\n", current->content);
//        current = current->next;
//    }
//}
//
//int main(void)
//{
//	t_list * test;
//
//	test = ft_lstnew(malloc(1));
//	ft_lstadd_back(&test, ft_lstnew(malloc(1)));
//	printf("before del :\n");
//	print_list(test);
//	ft_lstdelone(test->next, free);
//	test->next = NULL;
//	printf("after del :\n");
//	print_list(test);
//}
