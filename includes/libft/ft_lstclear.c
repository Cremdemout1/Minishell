/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno <bruno@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:18:42 by yohan             #+#    #+#             */
/*   Updated: 2024/07/10 20:30:55 by bruno            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*temp;

	while (*lst)
	{
		current = *lst;
		temp = current->next;
		del(current->content);
		free(current);
		*lst = temp;
	}
	*lst = NULL;
}

/*
int	main(void)
{
	int		i;
	t_list	*lst;
		char content[20];
	char	*mem_content;
	t_list	*node;
	t_list	*current;

	i = 1;
	lst = NULL;
	while (i <= 5)
	{
		snprintf(content, sizeof(content), "node #%d", i);
		mem_content = (char *)malloc(sizeof(char) * ft_strlen(content));
		if (mem_content == NULL)
			return (1);
		ft_memcpy(mem_content, content, ft_strlen(content) + 1);
		node = ft_lstnew(mem_content);
		ft_lstadd_back(&lst, node);
		i++;
		free(mem_content);
	}
	current = lst;
	while (current)
	{
		printf("%s\n", (char *)current->content);
		current = current->next;
	}
	ft_lstclear(&lst, &ft_free);
	return (0);
}
 */