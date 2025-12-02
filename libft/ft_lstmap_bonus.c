/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khadj-me <khalilhadjmes1@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 10:48:51 by khadj-me          #+#    #+#             */
/*   Updated: 2024/11/14 14:41:17 by khadj-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*curr;
	t_list	*temp;
	t_list	*new_lst;

	if (!lst || !f || !del)
		return (NULL);
	curr = lst;
	new_lst = ft_lstnew(f(curr->content));
	if (new_lst == NULL)
		return (free(new_lst), NULL);
	while (curr->next != NULL)
	{
		curr = curr->next;
		temp = ft_lstnew(f(curr->content));
		if (!temp)
			return (ft_lstclear(&new_lst, del), NULL);
		ft_lstadd_back(&new_lst, temp);
	}
	return (new_lst);
}

//void add_one(void * p) 
//{
//	++*(int*)p;
//}
//
//void print_list(t_list * head) 
//{
//    t_list * current = head;
//
//    while (current != NULL) {
//        printf("%d\n", *(int *)current->content);
//        current = current->next;
//    }
//}
//
//int main(void)
//{
//	int i;
//	t_list * test1;
//	t_list * test2;
//
//	i = 76;
//	test1 = ft_lstnew(&i);
//	ft_lstadd_back(&test1, ft_lstnew(&i));
//	ft_lstadd_back(&test1, ft_lstnew(&i));
//	ft_lstadd_back(&test1, ft_lstnew(&i));
//	//ft_lstadd_back(&test1, ft_lstnew(&i));
//	printf("original :\n")
//	print_list(test1);
//	test2 = ft_lstmap(test1, add_one, free);
//	printf("new one :\n")
//	print_list(test2);
//}