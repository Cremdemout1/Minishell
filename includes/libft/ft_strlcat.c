/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno <bruno@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 21:18:06 by yohan             #+#    #+#             */
/*   Updated: 2024/07/09 16:14:16 by bruno            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t sizeofbuf)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	k = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0')
		j++;
	if (sizeofbuf <= i)
		j += sizeofbuf;
	else
		j += i;
	while (src[k] != '\0' && i + 1 < sizeofbuf)
	{
		dest[i] = src[k];
		i++;
		k++;
	}
	dest[i] = '\0';
	return (j);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char dest1[25] = "yeayea";
	int  n = -1;
	char src[] = "nonono";
	printf("%zu\n", ft_strlcat(dest1, src, n));
	printf("%s\n", dest1);
	return (0);
} */