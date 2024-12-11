/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfernan <brfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 03:18:24 by bruno             #+#    #+#             */
/*   Updated: 2024/12/03 22:13:02 by brfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ignore_signal(int SIG, struct sigaction *sa)
{
	struct sigaction	original_sa;
	int					original_flags;

	original_flags = sa->sa_flags;
	sa->sa_handler = SIG_IGN;
	sa->sa_flags |= SA_SIGINFO;
	sigemptyset(&sa->sa_mask);
	sigaction(SIG, sa, &original_sa);
	sa->sa_flags = original_flags;
}

void	root_handler(int signal, siginfo_t *info, void *context)
{
	(void)info;
	(void)context;
	if (signal == SIGINT)
	{
		ft_printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

void	here_handler(int signal, siginfo_t *info, void *context)
{
	(void)info;
	(void)context;
	if (signal == SIGINT)
	{
		ft_printf("\n");
		exit (130);
	}
}

void	signal_aux(t_signal type, struct sigaction sa)
{
	if (type == HEREDOC_SIG)
	{
		sa.sa_sigaction = here_handler;
		sa.sa_flags = SA_SIGINFO;
		sigemptyset(&sa.sa_mask);
		sigaction(SIGINT, &sa, NULL);
		ignore_signal(SIGQUIT, &sa);
	}
	else if (type == IGNORE_SIG)
	{
		ignore_signal(SIGINT, &sa);
		ignore_signal(SIGQUIT, &sa);
	}
}

void	setup_signal(t_signal type)
{
	static struct sigaction	sa;

	if (type == ROOT_SIG)
	{
		sa.sa_sigaction = root_handler;
		sa.sa_flags = SA_SIGINFO;
		sigemptyset(&sa.sa_mask);
		sigaction(SIGINT, &sa, NULL);
		ignore_signal(SIGQUIT, &sa);
	}
	else if (type == CHILD_SIG)
	{
		sa.sa_handler = SIG_DFL;
		sa.sa_flags = 0;
		sigemptyset(&sa.sa_mask);
		sigaction(SIGINT, &sa, NULL);
		sigaction(SIGQUIT, &sa, NULL);
	}
	else
		signal_aux(type, sa);
}
