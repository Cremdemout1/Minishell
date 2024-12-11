/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraycmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfernan <brfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 16:51:17 by ycantin           #+#    #+#             */
/*   Updated: 2024/08/20 19:05:59 by brfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_arraycmp(char **arr1, char **arr2)
{
	int	i;

	if (!arr1 || !arr2)
		return (-1);
	if (ft_split_wordcount(arr1) != ft_split_wordcount(arr2))
		return (1);
	i = 0;
	while (arr1[i] && arr2[i])
	{
		if (ft_strcmp(arr1[i], arr2[i]) != 0)
			break ;
		i++;
	}
	if (i != ft_split_wordcount(arr1))
		return (1);
	return (0);
}

/* 

int main (void)
{
	char **arr1 = ft_split("hello world i am bruno", ' ');
	char **arr2 = ft_split("hello world i am bruno bruno", ' ');
	int ret = ft_arraycmp(arr1, arr2);
	if (ret == 0)
		printf("same\n");
	else if (ret == -1)
		printf("inv\n");
	else
		printf("diff\n");
	return (0);
} */