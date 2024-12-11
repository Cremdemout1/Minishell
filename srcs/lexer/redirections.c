/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno <bruno@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:46:14 by bruno             #+#    #+#             */
/*   Updated: 2024/12/06 00:47:49 by bruno            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	apply_heredoc(t_jobs *job, t_token *current, t_env *env)
{
	job->heredoc = 1;
	if (job->delimiters)
		free(job->delimiters);
	job->delimiters = ft_strdup(current->next->token);
	if (job->input)
		free(job->input);
	job->input = ft_strdup(job->heredoc_file);
	if (handle_heredoc(job, *env) < 0)
		ft_printf_fd (2, "error handling heredocs\n");
}

void	redir_error(char **to_change, t_env *env, char *str, int type)
{
	if (!env->redir_error)
	{
		if (type == 0)
			ft_printf_fd(2, "minishell: %s: ambiguous redirect\n", str);
		else if (type == 1)
			ft_printf_fd(2, "minishell: %s: No such file or directory\n", str);
	}
	env->redir_error = true;
	*to_change = ft_strdup("/dev/null");
}

void	apply_output(t_jobs *job, t_token *current, t_env *env)
{
	char	*temp;
	int		fd;

	if (current->next->token && (current->next->token[0] == '$'))
		return (redir_error(&job->output, env,
				current->next->token, 0), (void) NULL);
	temp = unquote_and_direct(current->next->token, env);
	free(current->next->token);
	current->next->token = temp;
	fd = open(current->next->token, O_CREAT | O_RDWR, 0644);
	if (fd > 0)
		close(fd);
	if (access(current->next->token, F_OK) != 0)
		redir_error(&job->output, env, current->next->token, 1);
	else
	{
		if (current->type == APPEND_OUT)
			job->append = 1;
		if (job->output)
			free(job->output);
		job->output = ft_strdup(current->next->token);
	}
}

void	apply_redir(t_token *current, t_jobs *job, t_env *env)
{
	char	*temp;

	if (current->type == HEREDOC)
		apply_heredoc(job, current, env);
	if (current->type == INPUT)
	{
		if (current->next->token && (current->next->token[0] == '$'))
			return (redir_error(&job->input, env,
					current->next->token, 0), (void) NULL);
		temp = unquote_and_direct(current->next->token, env);
		free(current->next->token);
		current->next->token = temp;
		if (access(current->next->token, F_OK) != 0)
			redir_error(&job->input, env, current->next->token, 1);
		else if (!env->redir_error)
		{
			if (job->input)
				free(job->input);
			job->input = ft_strdup(current->next->token);
		}
	}
	if (current->type == OUTPUT || current->type == APPEND_OUT)
		apply_output(job, current, env);
}
