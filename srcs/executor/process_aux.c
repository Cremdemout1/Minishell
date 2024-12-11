/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_aux.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno <bruno@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 19:13:31 by bruno             #+#    #+#             */
/*   Updated: 2024/12/02 16:00:42 by bruno            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*find_command_path(char	**cmd, t_env *env)
{
	char	**path_array;
	char	*path;
	int		i;

	path = ft_getenv("PATH", env->env);
	path_array = ft_split(path, ':');
	free (path);
	i = 0;
	while (path_array && path_array[i] && cmd[0][0] &&
			ft_strcmp(cmd[0], ".") && ft_strcmp(cmd[0], ".."))
	{
		path = ft_strjoin3(path_array[i], "/", cmd[0]);
		if (!path)
			return (free_array(path_array), NULL);
		if (access(path, F_OK) == 0)
			return (free_array(path_array), path);
		free (path);
		i++;
	}
	free_array(path_array);
	return (ft_printf_fd(2,
			"minishell: %s: command not found\n", cmd[0]), NULL);
}

void	execute_command(t_jobs *job, t_env *env)
{
	char	*path;

	path = find_command_path(job->job, env);
	if (!path)
		clean_exit(job, env, 127);
	execve(path, job->job, env->env);
	ft_printf_fd(2, "execve() failed\n");
	clean_exit(job, env, 127);
}

char	*find_executable_path(t_jobs *job, t_env *env)
{
	char	*path;
	char	cwd[PATH_MAX];

	if (job->job[0][0] == '/' || job->job[0][0] == '.')
	{
		if (opendir(job->job[0]))
			return (ft_printf_fd(2,
					"minishell: %s: Is a directory\n",
					job->job[0]), clean_exit(job, env, 126), NULL);
		path = ft_strdup(job->job[0]);
	}
	else
	{
		getcwd(cwd, PATH_MAX);
		path = ft_strjoin3(cwd, "/", job->job[0]);
		if (!path)
			clean_exit(job, env, 127);
	}
	if (access(path, X_OK) == 0)
		return (path);
	else if (access(path, F_OK) == 0)
		return (ft_printf_fd(2, " Permission denied\n"),
			clean_exit(job, env, 126), free(path), NULL);
	ft_printf_fd(2, "minishell: %s: No such file or directory\n", job->job[0]);
	return (clean_exit(job, env, 127), free(path), NULL);
}

void	execute_executable(t_jobs *job, t_env *env)
{
	char	*path;

	path = find_executable_path(job, env);
	execve(path, job->job, env->env);
	ft_printf_fd(2, "execve() failed\n");
	clean_exit(job, env, 127);
}

void	execute_job(t_jobs *job, t_env *env)
{
	setup_signal(CHILD_SIG);
	if (job->job[0] && ft_strchr(job->job[0], '/'))
		execute_executable(job, env);
	else if (job->job[0])
		execute_command(job, env);
	ft_printf_fd(2, "minishell: %s: command not found\n");
	clean_exit(job, env, 127);
}
