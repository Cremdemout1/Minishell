/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno <bruno@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 17:26:33 by bruno             #+#    #+#             */
/*   Updated: 2024/12/03 15:32:55 by bruno            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

bool	init_executor(t_jobs *job, t_env *env)
{
	if (!job)
		return (false);
	env->saved_stdin = dup(STDIN_FILENO);
	env->saved_stdout = dup(STDOUT_FILENO);
	env->pids = ft_calloc_pids(job);
	if (!env->pids)
		return (false);
	env->piped = false;
	return (true);
}

void	finish_executor(t_env *env)
{
	if (access(".heredoc", F_OK) == 0)
		remove(".heredoc");
	close(env->saved_stdin);
	close(env->saved_stdout);
	free (env->pids);
	env->redir_error = false;
}

void	job_reset(t_jobs *job, t_env *env)
{
	dup2(env->saved_stdin, STDIN_FILENO);
	dup2(env->saved_stdout, STDOUT_FILENO);
	if (job->heredoc_file && access(job->heredoc_file, F_OK) == 0)
		remove(job->heredoc_file);
}

void	executor(t_jobs *job, t_env *env)
{
	if (!init_executor(job, env))
		return ;
	while (job)
	{
		if (job->job)
			modify_array(job->job, env);
		if (!executor_input(job, env) || !executor_output(job, env))
		{
			skip_job(&job);
			continue ;
		}
		if (job->next && job->next->type == PIPE)
		{
			start_pipe(&job, env);
			continue ;
		}
		else if (job->job && env->piped)
			piped_process(job, env);
		else if (job->job)
			simple_process(job, env);
		if (!loop_executor(&job, env))
			break ;
	}
	finish_executor(env);
	return ;
}
