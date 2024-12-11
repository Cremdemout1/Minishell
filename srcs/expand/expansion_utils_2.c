/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno <bruno@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 17:53:14 by bruno             #+#    #+#             */
/*   Updated: 2024/12/02 23:26:20 by bruno            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

bool	is_empty_arg(char *str, char end)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != end)
	{
		if (ft_isascii(str[i]) && str[i] != '\0')
			return (true);
		i++;
	}
	return (false);
}
