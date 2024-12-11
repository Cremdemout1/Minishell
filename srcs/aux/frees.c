/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno <bruno@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 15:18:01 by ycantin           #+#    #+#             */
/*   Updated: 2024/12/02 23:01:17 by bruno            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	clean_exit(t_jobs *jobs, t_env *env, int status)
{
	if (jobs->job)
		clear_jobs(&jobs);
	close (env->saved_stdin);
	close (env->saved_stdout);
	if (env->env)
		free_array(env->env);
	if (env->pids)
		free (env->pids);
	rl_clear_history();
	exit (status);
}

void	clear_list(t_token **lst)
{
	t_token	*temp;
	t_token	*current;

	current = *lst;
	while (current)
	{
		temp = current->next;
		free(current->token);
		free(current);
		current = temp;
	}
	*lst = NULL;
}

void	clear_single_job(t_jobs **job)
{
	if ((*job)->job)
		free_array((*job)->job);
	if ((*job)->heredoc_file)
		free((*job)->heredoc_file);
	if ((*job)->input)
		free((*job)->input);
	if ((*job)->output)
		free((*job)->output);
	if ((*job)->delimiters)
		free((*job)->delimiters);
	free (*job);
}

void	clear_jobs(t_jobs **lst)
{
	t_jobs	*temp;
	t_jobs	*current;

	current = *lst;
	while (current)
	{
		temp = current->next;
		clear_single_job(&current);
		current = temp;
	}
	*lst = NULL;
}

void	free_all(t_token **list, char **array, char *message, int len)
{
	free_array(array);
	clear_list(list);
	write(1, message, len);
	exit(1);
}
