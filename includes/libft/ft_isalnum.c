/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfernan <brfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 12:42:24 by yohan             #+#    #+#             */
/*   Updated: 2024/09/05 15:17:47 by brfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int input)
{
	if ((input >= 97 && input <= 122) || (input >= 65 && input <= 90)
		|| (input >= 48 && input <= 57))
		return (1);
	return (0);
}

int	ft_isalnumund(int input)
{
	if ((input >= 97 && input <= 122) || (input >= 65 && input <= 90)
		|| (input >= 48 && input <= 57) || input == 95)
		return (1);
	return (0);
}
/*
int main (int argc, char *argv[])
{
	int	i;

	(void) argc;
	i = 0;
	while (argv[1][i])
	{
		printf("%d", ft_isalnum(argv[1][i]));
		i++;
	}
	return (0);
}
*/