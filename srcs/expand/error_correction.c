/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_correction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno <bruno@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 18:20:43 by ycantin           #+#    #+#             */
/*   Updated: 2024/11/14 16:47:50 by bruno            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	count(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
			i++;
		if (!str[i])
			break ;
		if (str[i] == '\'' || str[i] == '\"')
			count += count_quotes(str, &i) + 1;
		else if (str[i] == '&' || str[i] == '|'
			|| str[i] == '<' || str[i] == '>')
			count += count_special_chars(str, &i) + 1;
		else
			count += count_normal_chars(str, &i) + 1;
	}
	return (count);
}

void	split_quote(char *str, t_var_holder *h)
{
	char	quote;

	quote = str[h->i++];
	h->new[h->j++] = quote;
	while (str[h->i] && str[h->i] != quote)
		h->new[h->j++] = str[h->i++];
}

void	split_special_chars(char *str, t_var_holder *h)
{
	if (h->j > 0 && h->new[h->j - 1] != ' ')
		h->new[h->j++] = ' ';
	while (str[h->i] && (str[h->i] == '&' || str[h->i] == '|'
			|| str[h->i] == '<' || str[h->i] == '>'))
		h->new[h->j++] = str[h->i++];
	h->new[h->j++] = ' ';
}

void	handle_default_split(char *str, t_var_holder *h)
{
	while (str[h->i] && str[h->i] != '&' && str[h->i] != '|'
		&& str[h->i] != '<' && str[h->i] != '>'
		&& str[h->i] != '\t' && str[h->i] != ' ')
		h->new[h->j++] = str[h->i++];
	if (h->new[h->j - 1] != ' ' && str[h->i] != '\0')
		h->new[h->j++] = ' ';
}

char	*split_complex_args(char *str)
{
	t_var_holder	h;

	h.i = 0;
	h.j = 0;
	h.wc = count(str);
	h.new = malloc(sizeof(char) * (h.wc + 1));
	if (!h.new)
		return (NULL);
	while (str[h.i])
	{
		while (str[h.i] == ' ' || str[h.i] == '\t')
			h.i++;
		if (!str[h.i])
			break ;
		if (str[h.i] == '\'' || str[h.i] == '\"')
			split_quote(str, &h);
		else if (str[h.i] == '&' || str[h.i] == '|'
			|| str[h.i] == '<' || str[h.i] == '>')
			split_special_chars(str, &h);
		else
			handle_default_split(str, &h);
	}
	h.new[h.j] = '\0';
	return (h.new);
}
