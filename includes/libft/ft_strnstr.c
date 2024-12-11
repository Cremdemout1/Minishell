/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycantin <ycantin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 12:41:03 by yohan             #+#    #+#             */
/*   Updated: 2024/04/24 18:24:33 by ycantin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hay, const char *needle, size_t n)
{
	size_t	i;
	size_t	j;
	int		needlelen;

	i = 0;
	needlelen = ft_strlen(needle);
	if (needlelen == 0)
		return ((char *)hay);
	while (i < n && hay[i])
	{
		j = 0;
		while (needle[j] == hay[i + j] && (i + j) < n)
		{
			if (needle[j + 1] == '\0')
				return ((char *)hay + i);
			j++;
		}
		i++;
	}
	return (0);
}
/*

int main (void)
{
	char	*x;
	char	*y;

	x = "lorem ipsum dolor sit amet";
	y = "dolor";
	printf("%s\n", ft_strnstr(x, y, 15));
	printf("%s", strnstr(x, y, 15));
	return (0);
}
 */