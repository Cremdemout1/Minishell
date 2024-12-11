/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno <bruno@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 13:32:40 by yohan             #+#    #+#             */
/*   Updated: 2024/07/10 20:30:54 by bruno            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst)
	{
		del(lst->content);
		free(lst);
	}
}

/*
int main (void)
{
	int		i;
	t_list	*lst;
		char buffer[15];
	char	*content;
	t_list	*current;
	t_list	*new;
	t_list	*temp;

	i = 1;
	lst = NULL;
	while (i <= 5)
	{
		snprintf(buffer, sizeof(buffer), "node%d", i);
		content = (char *) malloc (sizeof(char) * (ft_strlen(buffer) + 1));
		if (content == NULL)
			return (1);
		ft_memcpy(content, buffer, ft_strlen(buffer) + 1);
		current = ft_lstnew(content);
		ft_lstadd_back (&lst, current);
		i++;
	}
	new = lst;
	temp = new -> next;
	if (i == 3)
		new = new -> next;
	if (new)
	{
		new -> next = temp -> next;
		ft_lstdelone (temp, ft_free);
	}
	new = lst;
	while (new)
	{
		printf ("%s\n", (char *)new -> content);
		new = new -> next;
	}
	return (0);
}
*/