/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfernan <brfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 00:13:28 by bruno             #+#    #+#             */
/*   Updated: 2024/12/03 21:31:11 by brfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_token	*developed_cmdline_tokenization(char *command_line)
{
	char	*simplified;
	char	*error;
	t_token	*list;
	t_token	*temp;

	list = NULL;
	error = "Minishell: syntax error near unexpected token `newline'\n";
	simplified = split_complex_args(command_line);
	tokenize(&list, simplified);
	free(simplified);
	temp = list;
	while (temp)
	{
		if (temp->type >= 4 && temp->type <= 7 && !temp->next)
		{
			ft_printf_fd(2, error);
			free(command_line);
			clear_list(&list);
			return (NULL);
		}
		temp = temp->next;
	}
	return (list);
}

char	**job_array(t_token **cur, t_jobs **job, t_env *env)
{
	int		i;
	char	**array;

	i = 0;
	array = malloc(sizeof(char *) * (count_tokens_in_job(*cur) + 1));
	if (!array)
		return (NULL);
	while (*cur && (*cur)->type != AND && (*cur)->type != OR
		&& (*cur)->type != PIPE)
	{
		if ((*cur)->type >= INPUT && (*cur)->type <= APPEND_OUT)
		{
			apply_redir(*cur, *job, env);
			*cur = (*cur)->next->next;
		}
		else
		{
			array[i++] = ft_strdup((*cur)->token);
			*cur = (*cur)->next;
		}
	}
	if (i == 0)
		return (free(array), NULL);
	array[i] = NULL;
	return (array);
}

void	make_job_list(t_jobs **job_list, t_token **tok_list, t_env *env)
{
	t_token	*cur;
	t_jobs	*new;
	int		i;

	i = 0;
	cur = *tok_list;
	while (cur)
	{
		new = addjob(NULL);
		if (cur && (cur->type == PIPE || cur->type == AND || cur->type == OR))
		{
			assign_values(&new, &cur, env);
			go_to_next_job(job_list, new);
			cur = cur->next;
			continue ;
		}
		if (new->heredoc_file)
			free(new->heredoc_file);
		new->heredoc_file = filename(i);
		new->job = job_array(&cur, &new, env);
		new->type = WORD;
		go_to_next_job(job_list, new);
		i++;
	}
}

t_jobs	*build(char *command_line, t_env *env)
{
	t_jobs	*jobs;
	t_token	*list;
	t_token	*last;

	if (!command_line || !command_line[0])
		return (NULL);
	jobs = NULL;
	list = NULL;
	last = NULL;
	list = developed_cmdline_tokenization(command_line);
	if (!list)
		return (NULL);
	if (parse(&list) == -1)
	{
		free(command_line);
		clear_list(&list);
		return (NULL);
	}
	last = get_last_tok(list);
	while (last && last->type >= PIPE && last->type <= OR && !last->next)
		if (parse_last_token(&command_line, &list, &last) == -1)
			return (NULL);
	make_job_list(&jobs, &list, env);
	clear_list(&list);
	return (free(command_line), jobs);
}
