/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycantin <ycantin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 12:43:24 by yohan             #+#    #+#             */
/*   Updated: 2024/04/24 18:24:36 by ycantin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		i;
	char	*s;

	i = ft_strlen(str);
	s = (char *)str;
	if (c == 0)
		return (s + i);
	while (i >= 0)
	{
		if (str[i] == (char)c)
			return (s + i);
		i--;
	}
	return (NULL);
}
/*
#include <string.h>

int main (void)
{
	char	str[10] = "123456789";

	printf("test: %s\n", ft_strrchr(str, 'a'));
	printf("test: %s\n", strrchr(str, 'a'));
	return (0);
}
*/