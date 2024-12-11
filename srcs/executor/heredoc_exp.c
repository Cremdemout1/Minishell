/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   heredoc.c										  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: ycantin <ycantin@student.42.fr>			+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/06/26 18:20:43 by ycantin		   #+#	#+#			 */
/*   Updated: 2024/08/29 18:59:07 by ycantin		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*no_quotes_hd(char *str, t_var_holder *h, t_env *env, int **expand_flag)
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
		h->temp = ft_strjoin(h->new, h->before);
		free(h->new);
		h->new = h->temp;
	}
	**expand_flag = 1;
	free(h->before);
	if (!h->new)
		return (NULL);
	return (h->new);
}

char	*single_quotes_hd(char *str, t_var_holder *h,
		char quote, int **expand_flag)
{
	if (!h->new)
		h->new = ft_strdup("");
	h->start = ++h->i;
	while (str[h->i] && str[h->i] != quote)
		h->i++;
	h->quoted = ft_strndup(str + h->start, h->i - h->start);
	if (!h->quoted)
		return (h->new);
	h->temp = ft_strdup(h->new);
	free(h->new);
	h->new = ft_strjoin(h->temp, h->quoted);
	free(h->quoted);
	free(h->temp);
	**expand_flag = 0;
	if (!h->new)
		return (NULL);
	return (h->new);
}

void	init_heredoc_exp(t_var_holder *h)
{
	h->new = NULL;
	h->before = NULL;
	h->quoted = NULL;
	h->after = NULL;
	h->temp = NULL;
	h->i = 0;
	h->start = 0;
}

void	heredoc_expand_check(int *expand_flag, t_jobs **job, t_env env)
{
	char			*str;
	t_var_holder	h;

	str = (*job)->delimiters;
	init_heredoc_exp(&h);
	if (is_empty_arg(str, '\'') || is_empty_arg(str, '\"'))
		h.new = ft_strdup("");
	while (str[h.i])
	{
		h.start = h.i;
		while (str[h.i] && str[h.i] != '\'' && str[h.i] != '\"')
			h.i++;
		if (h.i > h.start)
			h.new = no_quotes_hd(str, &h, &env, &expand_flag);
		if (str[h.i] == '\'' || str[h.i] == '\"')
			h.new = single_quotes_hd(str, &h, str[h.i], &expand_flag);
		if (str[h.i])
			h.i++;
	}
	free(str);
	(*job)->delimiters = h.new;
}
