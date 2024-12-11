/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycantin <ycantin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:42:26 by yohan             #+#    #+#             */
/*   Updated: 2024/04/24 18:24:30 by ycantin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*dest;

	i = 0;
	dest = (char *)malloc(((ft_strlen(s) + 1) * sizeof(char)));
	if (!dest)
		return (NULL);
	while (s[i])
	{
		dest[i] = f(i, s[i]);
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/*
char	wrapper(unsigned int n, char a)
{
	(void) n;
	a = ft_toupper(a);
	return (a);
}


int main (int argc, char *argv[])
{
	if (argc != 2)
		return (1);
	printf("original string: %s\n", argv[1]);
	argv[1] = ft_strmapi(argv[1], wrapper);
	printf("changed string: %s\n", argv[1]);
	free (argv[1]);
	return (0);
}
*/