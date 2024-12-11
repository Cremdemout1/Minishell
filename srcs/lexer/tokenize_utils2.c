/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfernan <brfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 20:06:08 by ycantin           #+#    #+#             */
/*   Updated: 2024/12/03 20:42:03 by brfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	take_care_quotes(t_var_holder *h, char *str, int *in_quote, char *quote)
{
	if (*in_quote && str[h->i] == *quote)
	{
		*in_quote = 0;
		*quote = '\0';
	}
	else
	{
		*in_quote = 1;
		*quote = str[h->i];
	}
	h->i++;
}

void	handle_whitespace(t_var_holder *h, char *str)
{
	if (h->i > h->j)
	{
		h->array[h->k] = ft_substr(str, h->j, h->i - h->j);
		h->k++;
	}
	while (str[h->i] && (str[h->i] == ' '
			|| str[h->i] == '\t' || str[h->i] == '\n'))
		h->i++;
	h->j = h->i;
}

void	add_last_segment(t_var_holder *h, char *str)
{
	if (h->i > h->j)
	{
		h->array[h->k] = ft_substr(str, h->j, h->i - h->j);
		h->k++;
	}
}

void	process_char(t_var_holder *h, char *str, int *in_quote, char *quote)
{
	if (*in_quote && str[h->i] != *quote)
		h->i++;
	else if (*in_quote)
		take_care_quotes(h, str, in_quote, quote);
	else if (str[h->i] == ' ' || str[h->i] == '\t' || str[h->i] == '\n')
		handle_whitespace(h, str);
	else if (str[h->i] == '\'' || str[h->i] == '\"')
		take_care_quotes(h, str, in_quote, quote);
	else
		h->i++;
}
