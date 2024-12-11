/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno <bruno@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 18:15:45 by bruno             #+#    #+#             */
/*   Updated: 2024/11/14 00:13:21 by bruno            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

bool	is_in_env(char *to_add, char **env)
{
	int		i;
	char	*temp1;
	char	*temp2;

	temp1 = NULL;
	temp2 = NULL;
	if (!to_add || !env)
		return (false);
	i = 0;
	temp1 = ft_substr(to_add, 0, len_to_equal(to_add));
	while (env[i])
	{
		temp2 = ft_substr(env[i], 0, len_to_equal(env[i]));
		if (ft_strcmp(temp1, temp2) == 0)
		{
			free (temp1);
			free (temp2);
			free (env[i]);
			env[i] = ft_strdup(to_add);
			return (true);
		}
		free (temp2);
		i++;
	}
	return (free (temp1), false);
}

bool	parse_export(char *str, int n)
{
	int	i;

	if (!str || !ft_isalphaund(str[0]))
		return (false);
	i = 0;
	while (i < n)
	{
		if (!ft_isalnumund(str[i]))
			return (false);
		i++;
	}
	return (true);
}

int	export_no_execd(char **env)
{
	int		i;
	char	*temp1;
	char	*temp2;

	i = 0;
	while (env[i])
	{
		temp1 = ft_substr(env[i], 0, len_to_equal(env[i]) + 1);
		temp2 = ft_substr(env[i], len_to_equal(env[i]) + 1, ft_strlen(env[i]));
		ft_printf("declare -x %s\"%s\"\n", temp1, temp2);
		free (temp1);
		free (temp2);
		i++;
	}
	return (0);
}

void	export_aux(t_jobs *job, char **new_env, t_env *env, int *status)
{
	int	i;
	int	k;

	i = -1;
	k = 1;
	while (env->env[++i])
		new_env[i] = ft_strdup(env->env[i]);
	while (job->job[k])
	{
		if (!parse_export(job->job[k], len_to_equal(job->job[k])))
		{
			ft_printf_fd(2,
				"minishell: export: '%s': not a valid identifier\n",
				job->job[k]);
			*status = 1;
		}
		else
		{
			if (!is_in_env(job->job[k], new_env))
				new_env[i] = ft_strdup(job->job[k]);
			i++;
		}
		k++;
	}
	new_env[i] = NULL;
}

int	caught_export(t_jobs *job, t_env *env)
{
	char	**new_env;
	int		i;
	int		parse;

	if (!job->job[1])
		return (export_no_execd(env->env));
	i = 0;
	parse = 0;
	while (job->job[++i])
	{
		if (!parse_export(job->job[i], len_to_equal(job->job[i])))
			parse++;
	}
	new_env = ft_calloc(sizeof(char *), ft_split_wordcount(env->env)
			+ ft_split_wordcount(job->job) - parse + 1);
	export_aux(job, new_env, env, &env->status);
	free_array(env->env);
	env->env = ft_calloc(sizeof(char *), ft_split_wordcount(new_env) + 1);
	i = -1;
	while (new_env[++i])
		env->env[i] = ft_strdup(new_env[i]);
	free_array(new_env);
	env->env[i] = NULL;
	return (env->status);
}
