/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfernan <brfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 16:52:00 by ycantin           #+#    #+#             */
/*   Updated: 2024/12/03 22:13:07 by brfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_token	*addtok(void *content)
{
	t_token	*list;

	list = malloc(sizeof(t_token));
	if (!list)
		return (NULL);
	list->token = content;
	list->next = NULL;
	return (list);
}

t_token	*get_last_tok(t_token *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	go_to_next(t_token **lst, t_token *new)
{
	t_token	*current;

	if (!new)
		return ;
	current = get_last_tok(*lst);
	if (lst && current)
		current->next = new;
	else
		*lst = new;
}

int	define_type(char *str)
{
	int	type;

	if (strcmp(str, "||") == 0)
		type = OR;
	else if (ft_strcmp(str, "&&") == 0)
		type = AND;
	else if (ft_strcmp(str, "|") == 0)
		type = PIPE;
	else if (ft_strcmp(str, "<") == 0)
		type = INPUT;
	else if (ft_strcmp(str, ">") == 0)
		type = OUTPUT;
	else if (ft_strcmp(str, "<<") == 0)
		type = HEREDOC;
	else if (ft_strcmp(str, ">>") == 0)
		type = APPEND_OUT;
	else
		type = WORD;
	return (type);
}

void	modify_array(char **array, t_env *env)
{
	int		i;
	char	*temp;

	i = 0;
	while (array[i])
	{
		temp = unquote_and_direct(array[i], env);
		free(array[i]);
		array[i] = temp;
		i++;
	}
	env->status = 0;
}
