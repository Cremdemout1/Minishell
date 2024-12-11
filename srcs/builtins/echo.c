/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno <bruno@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 04:38:31 by bruno             #+#    #+#             */
/*   Updated: 2024/11/11 21:27:07 by bruno            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	n_flag(char **strs)
{
	int		i;
	int		j;

	i = 1;
	while (strs[i])
	{
		if (strs[i][0] == '-' && strs[i][1] == 'n')
		{
			j = 2;
			while (strs[i][j] == 'n')
				j++;
			if (strs[i][j])
				break ;
		}
		else
			break ;
		i++;
	}
	return (i);
}

int	caught_echo(t_jobs *job)
{
	int		i;
	bool	has_n_flag;

	if (!job->job[1])
		return (ft_nl_fd(1), 0);
	has_n_flag = false;
	i = n_flag(job->job);
	if (i > 1)
		has_n_flag = true;
	while (job->job[i])
	{
		if (job->job[i][0])
			ft_printf_fd(1, "%s", job->job[i]);
		if (job->job[i + 1])
			ft_printf_fd(1, " ");
		i++;
	}
	if (!has_n_flag)
		ft_printf_fd(1, "\n");
	return (0);
}
