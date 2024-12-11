/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_redirs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno <bruno@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 16:40:37 by bruno             #+#    #+#             */
/*   Updated: 2024/12/02 23:37:53 by bruno            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

bool	executor_input(t_jobs *job, t_env *env)
{
	char	*temp;
	int		redirected_input;

	if (!job->input)
		return (true);
	temp = unquote_and_direct(job->input, env);
	if (job->input)
		free (job->input);
	job->input = temp;
	if (ft_strcmp(job->input, "/dev/null") == 0)
		return (env->status = 1, false);
	redirected_input = open(job->input, O_RDONLY);
	dup2(redirected_input, STDIN_FILENO);
	close(redirected_input);
	return (true);
}

bool	executor_output(t_jobs *job, t_env *env)
{
	char	*temp;
	int		redirected_output;

	if (!job->output)
		return (true);
	temp = unquote_and_direct(job->output, env);
	if (job->output)
		free (job->output);
	job->output = temp;
	if (ft_strcmp(job->output, "/dev/null") == 0)
		return (env->status = 1, false);
	if (job->append)
		redirected_output = open(job->output,
				O_CREAT | O_APPEND | O_RDWR, 0644);
	else
	{
		if (access(job->output, F_OK) == 0)
			remove(job->output);
		redirected_output = open(job->output, O_CREAT | O_RDWR, 0644);
	}
	dup2(redirected_output, STDOUT_FILENO);
	close(redirected_output);
	return (true);
}

void	start_pipe(t_jobs **job, t_env *env)
{
	env->piped = true;
	piped_process((*job), env);
	skip_job_2(job);
}

void	skip_job(t_jobs **job)
{
	t_jobs	*temp;

	temp = *job;
	*job = (*job)->next;
	clear_single_job(&temp);
}

void	skip_job_2(t_jobs **job)
{
	t_jobs	*temp1;
	t_jobs	*temp2;

	temp1 = *job;
	temp2 = (*job)->next;
	*job = (*job)->next->next;
	clear_single_job(&temp1);
	clear_single_job(&temp2);
}
