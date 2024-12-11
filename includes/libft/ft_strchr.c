/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno <bruno@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 12:42:58 by yohan             #+#    #+#             */
/*   Updated: 2024/07/10 20:30:37 by bruno            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != (char)c && s[i] != '\0')
		s++;
	if (s[i] == (char)c)
		return ((char *)s);
	return (0);
}

/*
int main (void)
{
	char	*x;
	char	y;

	x = "hello my good friendz";
	y = '\0';
	printf("%s", ft_strchr(x, (int) y));
	return (0);
}
*/