/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfernan <brfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 17:26:33 by bruno             #+#    #+#             */
/*   Updated: 2024/12/03 21:30:27 by brfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	clean_up_build(t_token **list, char *cmd_line)
{
	clear_list(list);
	free(cmd_line);
}

int	syntax_error(t_token *cur, t_token **token, t_var_holder *h)
{
	h->temp = "minishell: syntax error near unexpected token `";
	ft_printf_fd(2, "%s%s\'\n", h->temp, cur->token);
	clear_list(token);
	return (-1);
}

int	secondquote(char *line)//rather not use
{
	int		i;
	int		error;
	int		inside;
	char	quote;

	i = 0;
	error = 0;
	inside = 0;
	while (line[i])
	{
		if (!inside && (line[i] == '\'' || line[i] == '\"'))
		{
			quote = line[i];
			inside = 1;
			error = 1;
		}
		else if (inside == 1 && line[i] == quote)
		{
			error = 0;
			inside = 0;
		}
		i++;
	}
	return (error);
}
