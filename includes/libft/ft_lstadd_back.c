/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno <bruno@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 12:53:04 by yohan             #+#    #+#             */
/*   Updated: 2024/07/10 20:30:56 by bruno            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*current;

	if (!new)
		return ;
	current = ft_lstlast(*lst);
	if (lst && current)
		current->next = new;
	else
		*lst = new;
}
/*
int main (void)
{
	t_list	*list;
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;
	t_list	*node4;
	t_list	*node5;
	t_list	*new;
	char	*last_string;

	list = NULL;
	node1 = ft_lstnew("n1");
	node2 = ft_lstnew("n2");
	node3 = ft_lstnew("n3");
	node4 = ft_lstnew("n4");
	node5 = ft_lstnew("n5");
	new = ft_lstnew("New addition!");
	ft_lstadd_front(&list, node1);
	ft_lstadd_front(&list, node2);
	ft_lstadd_front(&list, node3);
	ft_lstadd_front(&list, node4);
	ft_lstadd_front(&list, node5);
	ft_lstadd_back(&list, new);
	last_string = ft_lstlast(list) -> content;
	printf("%s\n", last_string);
	return (0);
}
*/