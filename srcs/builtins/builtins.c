/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno <bruno@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 18:15:45 by bruno             #+#    #+#             */
/*   Updated: 2024/11/22 13:23:35 by bruno            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	try_builtins(t_jobs *job, t_env *env)
{
	int	status;

	status = 200;
	if (!job->job[0])
		return (status);
	if (ft_strcmp(job->job[0], "echo") == 0)
		status = caught_echo(job);
	else if (ft_strcmp(job->job[0], "pwd") == 0)
		status = caught_pwd();
	else if (ft_strcmp(job->job[0], "export") == 0)
		status = caught_export(job, env);
	else if (ft_strcmp(job->job[0], "unset") == 0)
		status = caught_unset(job, env);
	else if (ft_strcmp(job->job[0], "env") == 0)
		status = caught_env(job, env);
	else if (ft_strcmp(job->job[0], "exit") == 0)
		status = caught_exit(job, env, env->piped);
	if (env->piped && status != 200)
		clean_exit(job, env, status);
	return (status);
}
