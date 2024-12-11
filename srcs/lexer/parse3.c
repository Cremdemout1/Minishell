/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfernan <brfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 20:29:18 by ycantin           #+#    #+#             */
/*   Updated: 2024/12/03 20:43:57 by brfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

bool	update_quote_status(char c, bool *in_sq, bool *in_dq)
{
	if (c == '\'' && !(*in_dq))
		*in_sq = !(*in_sq);
	else if (c == '\"' && !(*in_sq))
		*in_dq = !(*in_dq);
	return (*in_sq || *in_dq);
}

int	handle_special_chars(t_token *t, int i, t_var_holder *h)
{
	if (t->token[i] == '&' || t->token[i] == '|')
	{
		if (start_string_parse(t->token + (i + 1), t->token[i], h) == -1)
			return (-1);
	}
	return (0);
}

int	handle_redirects(t_token *t, int i, t_var_holder *h)
{
	t_var_holder	tmp;

	tmp.temp = "minishell: syntax error near unexpected token `newline'\n";
	tmp.temp2 = "minishell: syntax error near unexpected token `";
	tmp.j = i;
	tmp.count = 0;
	while (t->token[tmp.j] && (t->token[tmp.j] == '<'
			|| t->token[tmp.j] == '>'))
	{
		tmp.j++;
		tmp.count++;
	}
	if (tmp.count > 2)
		return (ft_printf_fd(2, "%s%c\n"
				, tmp.temp2, t->token[tmp.count - 1]), -1);
	tmp.len = ft_strlen(t->token) - 1;
	if (tmp.len != 1 && (t->token[tmp.len] == '<' || t->token[tmp.len] == '>')
		&& !t->next)
		return (ft_printf_fd(2, "%s", tmp.temp), -1);
	if (start_string_parse(t->token + (i + 1), t->token[i], h) == -1)
		return (-1);
	return (0);
}
