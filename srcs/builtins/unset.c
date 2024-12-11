/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno <bruno@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 23:09:17 by bruno             #+#    #+#             */
/*   Updated: 2024/11/12 17:49:23 by bruno            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	unset_aux(char **to_remove, char **env)
{
	int	i;

	while (*to_remove)
	{
		i = 0;
		if (!env)
			return (1);
		while (env && env[i]
			&& ft_strncmp(env[i], *to_remove, ft_strlen(*to_remove)))
			i++;
		if (!env[i])
			return (1);
		free (env[i]);
		while (env[i])
		{
			env[i] = env[i + 1];
			i++;
		}
		to_remove++;
	}
	return (0);
}

int	caught_unset(t_jobs *job, t_env *env)
{
	if (!job->job[1])
		return (0);
	unset_aux(job->job + 1, env->env);
	return (0);
}
