/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfernan <brfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 19:15:54 by bruno             #+#    #+#             */
/*   Updated: 2024/12/03 22:18:23 by brfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_getpid(void)
{
	int		fd;
	char	buffer[256];
	int		pid;

	fd = open("/proc/self/stat", O_RDONLY);
	if (fd < 0)
		return (ft_putendl_fd("minishell: getpid() error", 2), 0);
	read(fd, buffer, 255);
	close (fd);
	pid = ft_atoi(buffer);
	return (pid);
}

char	**dup_env(char **envp)
{
	char	**new_env;
	char	*temp;
	int		i;

	i = 0;
	new_env = ft_calloc(sizeof(char *), ft_split_wordcount(envp) + 2);
	if (!new_env || !envp || !envp[0])
		return (NULL);
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "SHLVL=", 6) == 0)
		{
			temp = ft_itoa(ft_atoi(envp[i] + 6) + 1);
			new_env[i] = ft_strjoin("SHLVL=", temp);
			free (temp);
		}
		else
			new_env[i] = ft_strdup(envp[i]);
		if (!new_env[i])
			return (free_array(new_env), NULL);
		i++;
	}
	new_env[i] = NULL;
	return (new_env);
}

t_env	no_env(void)
{
	t_env	new_env;
	char	*temp;
	char	buf[PATH_MAX];

	new_env.env = malloc(sizeof (char *) * 3);
	if (!new_env.env)
		return (ft_printf_fd(2, "error allocating private path\n"), new_env);
	temp = ft_strjoin("PATH=/bin:/sbin:/usr/bin:/usr/sbin:",
			"/usr/local/bin:/usr/local/sbin:/snap/bin:");
	new_env.env[0] = ft_strdup(temp);
	free (temp);
	new_env.env[1] = ft_strjoin("PWD=", getcwd(buf, PATH_MAX));
	new_env.env[2] = NULL;
	return (new_env);
}

t_env	init_env(char **envp)
{
	t_env	env;

	env.env = NULL;
	env.redir_error = false;
	env.status = 0;
	if (!envp || !envp[0])
		return (no_env());
	else
		env.env = dup_env(envp);
	return (env);
}

int	count_processes(t_jobs **jobs)
{
	int		i;
	t_jobs	*job;

	i = 0;
	job = *jobs;
	while (job)
	{
		if (job->type == PIPE || job->job)
			i++;
		job = job->next;
	}
	return (i + 1);
}
