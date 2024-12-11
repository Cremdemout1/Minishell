/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno <bruno@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:48:00 by ycantin           #+#    #+#             */
/*   Updated: 2024/07/10 20:30:50 by bruno            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*iter;
	t_list	*new_lst;

	new_lst = NULL;
	if (!lst || !f)
		return (NULL);
	while (lst)
	{
		iter = ft_lstnew(f(lst->content));
		if (!iter)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, iter);
		lst = lst->next;
	}
	return (new_lst);
}
/*
void	*wrapper(void *f)
{
	char	*temp;
	int		i;

	temp = ft_strdup((const char *)f);
	if (temp == NULL)
		return (NULL);
	i = 0;
	while(temp[i])
	{
		temp[i] = ft_tolower(temp[i]);
		i++;
	}
	return ((void *)temp);
}

void	del_wrapper(void *content)
{
	t_list	*temp;

	temp = (t_list *)content;
	ft_lstclear(&temp, free);
}
int main (void)
{
	t_list	*list;
	t_list	*node;
	t_list	*node1;
	t_list	*node2;
	t_list	*temp;

	list = NULL;
	node = ft_lstnew("YEE");
	node1 = ft_lstnew("HAW");
	node2 = ft_lstnew("MF");
	ft_lstadd_back(&list, node);
	ft_lstadd_back(&list, node1);
	ft_lstadd_back(&list, node2);
	temp = list;
	while (temp)
	{
		printf ("%s\n", (char *)temp->content);
		temp = temp->next;
	}
	write (1, "\n", 1);
	list = ft_lstmap(list, wrapper, del_wrapper);
	temp = list;
	while (temp)
	{
		printf ("%s\n", (char *)temp->content);
		temp = temp->next;
	}
	return (0);
}
*/