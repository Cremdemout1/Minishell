/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno <bruno@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 11:13:05 by yohan             #+#    #+#             */
/*   Updated: 2024/07/10 20:30:51 by bruno            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

/*
int main (void)
{
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;
	t_list	*node4;
	t_list	*node5;
	t_list	*lst;
	char	*str;

	node1 = ft_lstnew("one");
	node2 = ft_lstnew("two");
	node3 = ft_lstnew("three");
	node4 = ft_lstnew("four");
	node5 = ft_lstnew("Last node");
	lst = NULL;
	ft_lstadd_front(&lst, node1);
	ft_lstadd_front(&lst, node2);
	ft_lstadd_front(&lst, node3);
	ft_lstadd_front(&lst, node4);
	ft_lstadd_front(&lst, node5);
	ft_lstlast(lst);
	str = lst -> content;
	printf ("%s\n", str);
	return (0);
}
*/