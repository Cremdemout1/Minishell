/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno <bruno@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 12:43:19 by yohan             #+#    #+#             */
/*   Updated: 2024/08/04 18:20:07 by bruno            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && s1[i] == s2[i] && i < (n - 1))
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	ft_envnamecmp(char *s1, char *s2)
{
	size_t	i;
	int		calc;

	i = 0;
	if (!s1 || !s2)
		return (-1);
	while (s1[i] && s2[i] && s1[i] == s2[i] && s1[i] != '=' && s2[i] != '=')
		i++;
	calc = (unsigned char)s1[i] - (unsigned char)s2[i];
	if (calc == 0)
		return (0);
	return (1);
}
/* 

int main (void)
{
	char	*x;
	char	*y;

	x = "he=a";
	y = "hell=world";
	printf("%d\n", ft_envnamecmp(x, y));
	return (0);
} */