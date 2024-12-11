/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno <bruno@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 12:41:31 by yohan             #+#    #+#             */
/*   Updated: 2024/07/09 16:14:19 by bruno            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	j;
	size_t	len;

	j = 0;
	len = 0;
	while (src[len])
		len++;
	if (size == 0)
		return (len);
	while (src[j] && j < (size - 1))
	{
		dest[j] = src[j];
		j++;
	}
	dest[j] = '\0';
	return (len);
}
/*
int	main (void)
{
	char	x[20];
	char	y[10];

	y[10] = "hello";
	printf("%zu", ft_strlcpy(x, y, 20));
	return (0);
}
 */