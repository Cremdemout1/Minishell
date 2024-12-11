/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfernan <brfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 17:26:33 by bruno             #+#    #+#             */
/*   Updated: 2024/12/03 21:30:55 by brfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	check_separator_syntax(char *str, char separator, int dir)
{
	char	*newline;
	char	*unexpected;

	newline = "minishell: syntax error near unexpected token `newline'\n";
	unexpected = "minishell: syntax error near unexpected token `";
	if (!dir)
	{
		if (*(str + 1) == separator && !*(str + 2))
			ft_printf_fd(2, newline);
		else if (!*(str + 2))
			ft_printf_fd(2, newline);
	}
	else
	{
		if (*(str + 1) && *(str + 1) == separator)
			ft_printf_fd(2, "%s%c%c\'\n", unexpected, separator, separator);
		else
			ft_printf_fd(2, "%s%c\'\n", unexpected, separator);
	}
}

int	syntax_check_wrapper(char *str, char target)
{
	if (*(str + 1) == '>')
		return (check_separator_syntax(str, '>', 0), -1);
	else if (*(str + 1) == '<')
		return (check_separator_syntax(str, '<', 0), -1);
	else
		return (check_separator_syntax(str, target, 1), -1);
	return (0);
}

int	parse_string(char *str, t_var_holder *h)
{
	if (*str && *str == h->b)
		return (syntax_check_wrapper(str, h->b));
	else if (*str && *str == h->c)
		return (syntax_check_wrapper(str, h->c));
	else if (*str && *str == h->d)
		return (syntax_check_wrapper(str, h->d));
	return (0);
}

int	start_string_parse(char *str, char delimiter, t_var_holder *h)
{
	if (delimiter == '&')
	{
		h->b = '|';
		h->c = '<';
		h->d = '>';
	}
	else if (delimiter == '|')
	{
		h->b = '&';
		h->c = '<';
		h->d = '>';
	}
	else if (delimiter == '<')
	{
		h->b = '&';
		h->c = '|';
		h->d = '>';
	}
	else if (delimiter == '>')
	{
		h->b = '&';
		h->c = '|';
		h->d = '<';
	}
	return (parse_string(str, h));
}

int	parse_token(t_token *t, bool *in_sq, bool *in_dq, t_var_holder *h)
{
	int	i;

	i = 0;
	while (t->token[i])
	{
		if (update_quote_status(t->token[i], in_sq, in_dq))
		{
			i++;
			continue ;
		}
		if (handle_special_chars(t, i, h) == -1)
			return (-1);
		if (t->token[i] == '<' || t->token[i] == '>')
		{
			if (handle_redirects(t, i, h) == -1)
				return (-1);
		}
		i++;
	}
	return (0);
}
