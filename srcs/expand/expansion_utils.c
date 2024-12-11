/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno <bruno@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 17:53:14 by bruno             #+#    #+#             */
/*   Updated: 2024/12/02 23:05:45 by bruno            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*no_expansion(char *str, t_var_holder h)
{
	h.before = ft_strndup(str + h.start, h.i - h.start);
	if (!h.before)
		return (NULL);
	if (!h.result)
		h.temp = ft_strdup(h.before);
	else
	{
		h.temp = ft_strjoin(h.result, h.before);
		free(h.result);
	}
	free (h.before);
	return (h.temp);
}

void	handle_dllr_or_qstn(char *str, t_var_holder *h, t_env *env)
{
	if (str[h->i] == '$')
	{
		h->expanded = ft_itoa(ft_getpid());
		h->i++;
	}
	else if (str[h->i] == '?')
	{
		h->expanded = ft_itoa(env->status);
		h->i++;
	}
}

char	*expansion(char *str, t_var_holder *h, t_env *env)
{
	if (str[h->i] == '\0' || str[h->i] == ' ' || str[h->i] == '\t')
		h->expanded = ft_strdup("$");
	else if (str[h->i] == '$' || str[h->i] == '?')
		handle_dllr_or_qstn(str, h, env);
	else
	{
		while (str[h->i] && (ft_isalnum(str[h->i]) || str[h->i] == '_'))
			h->i++;
		h->temp2 = ft_strndup(str + h->start, h->i - h->start);
		h->expanded = ft_getenv(h->temp2 + 1, env->env);
		if (!h->expanded)
			h->expanded = ft_strdup("");
		free(h->temp2);
	}
	h->temp = ft_strjoin(h->result, h->expanded);
	if (h->result)
		free(h->result);
	h->result = h->temp;
	free(h->expanded);
	h->start = h->i;
	return (h->result);
}

char	*expansion_loop(char *str, t_var_holder *h, t_env *env)
{
	while (str[h->i])
	{
		while (str[h->i] && str[h->i] != '$')
			h->i++;
		if (h->i > h->start)
			h->result = no_expansion(str, *h);
		if (str[h->i] == '$')
		{
			if (str[h->i + 1] == '\'' || str[h->i + 1] == '\"')
				h->i++;
			else
			{
				h->start = h->i;
				h->i++;
				h->result = expansion(str, h, env);
			}
		}
	}
	return (h->result);
}

char	*expand(char *str, t_env *env)
{
	t_var_holder	h;

	h.expanded = NULL;
	h.before = NULL;
	h.temp = NULL;
	h.result = NULL;
	h.i = 0;
	h.start = 0;
	return (expansion_loop(str, &h, env));
}
