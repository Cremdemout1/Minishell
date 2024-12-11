/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno <bruno@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 12:42:12 by yohan             #+#    #+#             */
/*   Updated: 2024/07/10 20:30:58 by bruno            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int input)
{
	if (input >= 32 && input <= 126)
		return (1);
	return (0);
}
/*
int main (void)
{
	int	i;

	i = 0;
	while (i <= 47)
	{
		printf("%d",ft_isprint(i));
		i++;
	}
	return (0);
}
*/