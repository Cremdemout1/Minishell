/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno <bruno@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 12:42:43 by yohan             #+#    #+#             */
/*   Updated: 2024/07/10 20:30:44 by bruno            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*ptr;
	const char	*copd;

	i = 0;
	ptr = (char *)dest;
	copd = (const char *)src;
	if (dest == NULL && src == NULL)
		return (NULL);
	while (i < n)
	{
		ptr[i] = copd[i];
		i++;
	}
	return (dest);
}
/*
#include <strings.h>

int	main(void)
{
	char	dest[0];
	char	src[];

	src[] = "";
	printf("%s\n", (char *) ft_memcpy(dest, src, 10));
	printf("%s", (char *) memcpy(dest, src, 10));
	return (0);
}
 */