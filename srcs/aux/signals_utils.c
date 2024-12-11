/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfernan <brfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 23:20:22 by bruno             #+#    #+#             */
/*   Updated: 2024/12/03 22:15:46 by brfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	eof_sig(char *line, t_env *env)
{
	free (line);
	ft_printf("exit\n");
	if (env->env)
		free_array(env->env);
	rl_clear_history();
	exit (env->status);
}
