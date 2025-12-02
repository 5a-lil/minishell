/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khadj-me <khalilhadjmes1@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 09:34:38 by khadj-me          #+#    #+#             */
/*   Updated: 2024/11/14 14:41:27 by khadj-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*curr;

	curr = lst;
	if (lst == NULL)
		return (0);
	while (curr->next != NULL)
		curr = curr->next;
	return (curr);
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
//	ft_lstadd_back(&test, ft_lstnew(malloc(1)));
//	ft_lstadd_back(&test, ft_lstnew(malloc(1)));
//	ft_lstadd_back(&test, ft_lstnew(malloc(2)));
//	printf("entire list :\n");
//	print_list(test);
//	printf("last of list :\n");
//	printf("%p\n", ft_lstlast(test)->content);
//}
