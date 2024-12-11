/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno <bruno@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 17:53:14 by bruno             #+#    #+#             */
/*   Updated: 2024/12/02 23:05:04 by bruno            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*no_quotes(char *str, t_var_holder *h, t_env *env)
{
	h->temp = ft_strndup(str + h->start, h->i - h->start);
	if (!h->temp)
		return (h->new);
	h->before = expand(h->temp, env);
	free(h->temp);
	if (!h->before)
		return (h->new);
	if (!h->new)
		h->new = ft_strdup(h->before);
	else
	{
		if (ft_strcmp(h->new, "$") == 0)
			free_and_allocate(&h->new, h->before, false);
		else
		{
			h->temp = ft_strjoin(h->new, h->before);
			free(h->new);
			h->new = h->temp;
		}
	}
	free(h->before);
	if (!h->new)
		return (NULL);
	return (h->new);
}

char	*single_quotes(char *str, t_var_holder *h)
{
	if (!h->new)
		h->new = ft_strdup("");
	h->start = ++h->i;
	while (str[h->i] && str[h->i] != '\'')
		h->i++;
	h->quoted = ft_strndup(str + h->start, h->i - h->start);
	if (!h->quoted)
		return (h->new);
	h->temp = ft_strdup(h->new);
	free(h->new);
	h->new = ft_strjoin(h->temp, h->quoted);
	free(h->quoted);
	free(h->temp);
	if (!h->new)
		return (NULL);
	return (h->new);
}

char	*double_quotes(char *str, t_var_holder *h, t_env *env)
{
	h->start = ++h->i;
	while (str[h->i] && str[h->i] != '\"')
		h->i++;
	h->temp = no_quotes(str, h, env);
	return (h->new);
}

void	init_var_holder(t_var_holder *holder)
{
	holder->new = NULL;
	holder->before = NULL;
	holder->quoted = NULL;
	holder->after = NULL;
	holder->temp = NULL;
	holder->i = 0;
	holder->start = 0;
}

char	*unquote_and_direct(char *str, t_env *env)
{
	t_var_holder	h;

	init_var_holder(&h);
	if (is_empty_arg(str, '\'') || is_empty_arg(str, '\"'))
		h.new = ft_strdup("");
	while (str[h.i])
	{
		h.start = h.i;
		while (str[h.i] && str[h.i] != '\'' && str[h.i] != '\"')
			h.i++;
		if (h.i > h.start || h.i == '$')
			h.new = no_quotes(str, &h, env);
		if (str[h.i] == '\'')
			h.new = single_quotes(str, &h);
		else if (str[h.i] == '\"')
			h.new = double_quotes(str, &h, env);
		if (str[h.i])
			h.i++;
	}
	return (h.new);
}
