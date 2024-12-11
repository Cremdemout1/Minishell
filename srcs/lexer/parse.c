/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno <bruno@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 17:26:33 by bruno             #+#    #+#             */
/*   Updated: 2024/12/06 00:47:23 by bruno            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	parse_redirections(t_token **token, t_token *cur, int flag)
{
	char	*nl;
	char	*unexp;

	nl = "minishell: syntax error near unexpected token`\\n\'\n";
	unexp = "minishell: syntax error near unexpected token `";
	if (!cur->next)
	{
		ft_printf_fd(2, "%s", nl);
		clear_list(token);
		return (flag + 1);
	}
	else if (cur->next && cur->next->type != WORD)
	{
		ft_printf_fd(2, "%s%s\'\n", unexp, cur->next->token);
		clear_list(token);
		return (flag + 1);
	}
	return (flag);
}

int	parse_separators(t_token **token, t_token *cur, int flag)
{
	char	*message;

	message = "minishell: syntax error near unexpected token `";
	if (cur->next && cur->next->type >= PIPE && cur->next->type <= OR)
	{
		if (cur->type >= PIPE && cur->type <= OR)
		{
			ft_printf_fd(2, "%s%s\'\n", message, cur->next->token);
			clear_list(token);
			return (flag + 1);
		}
	}
	return (flag);
}

int	parse_seps_and_redirs(t_token **token, t_token *cur)
{
	int	flag;

	flag = 0;
	while (cur && cur->next)
	{
		if (cur->type >= INPUT && cur->type <= APPEND_OUT)
		{
			flag = parse_redirections(token, cur, flag);
			if (flag != 0)
				return (-1);
		}
		if (cur->type >= PIPE && cur->type <= OR)
		{
			flag = parse_separators(token, cur, flag);
			if (flag != 0)
				return (-1);
		}
		cur = cur->next;
	}
	return (0);
}

int	parse(t_token **token)
{
	t_var_holder	h;
	t_token			*cur;
	bool			in_sq;
	bool			in_dq;

	cur = *token;
	if (cur && cur->type >= PIPE && cur->type <= OR)
		return (syntax_error(cur, token, &h));
	if (parse_seps_and_redirs(token, cur) == -1)
		return (-1);
	cur = *token;
	while (cur)
	{
		in_sq = false;
		in_dq = false;
		if (parse_token(cur, &in_sq, &in_dq, &h) == -1)
			return (-1);
		cur = cur->next;
	}
	if (cur && cur->type >= PIPE && cur->type <= OR)
		return (syntax_error(cur, token, &h));
	return (0);
}

int	parse_last_token(char **cmd_line, t_token **list, t_token **last)
{
	char	*line;
	char	*new;
	char	*converted;

	line = readline("> ");
	if (!line)
		return (clean_up_build(list, *cmd_line), -1);
	new = ft_strjoin(*cmd_line, line);
	free(*cmd_line);
	free(line);
	*cmd_line = new;
	clear_list(list);
	converted = split_complex_args(*cmd_line);
	tokenize(list, converted);
	free(converted);
	*last = get_last_tok(*list);
	if (parse(list) == -1)
	{
		clean_up_build(list, *cmd_line);
		return (-1);
	}
	return (0);
}
