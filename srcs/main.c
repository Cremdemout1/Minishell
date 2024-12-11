/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfernan <brfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 16:43:23 by ycantin           #+#    #+#             */
/*   Updated: 2024/12/03 21:57:03 by brfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	minishell(char **envp)
{
	char	*line;
	t_env	env;
	t_jobs	*jobs;
	t_jobs	*current;

	env = init_env(envp);
	while (1)
	{
		setup_signal(ROOT_SIG);
		line = readline("Minishell$ ");
		if (!line)
			eof_sig(line, &env);
		if (line && line[0])
			add_history(line);
		if (secondquote(line) == 1)
		{
			free(line);
			ft_printf("minishell: unclosed quote\n");
			continue ;
		}
		jobs = build(line, &env);
		current = jobs;
		executor(current, &env);
	}
}

int	main(int ac, char **av, char **envp)
{
	(void)av;
	if (ac != 1)
		return (1);
	minishell(envp);
	return (0);
}
