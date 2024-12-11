/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycantin <ycantin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:36:30 by ycantin           #+#    #+#             */
/*   Updated: 2024/04/24 18:24:39 by ycantin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int	i;
	int	start;
	int	end;

	i = 0;
	start = 0;
	end = 0;
	if (s1 == NULL)
		return (NULL);
	if (set == NULL)
		return ((char *)s1);
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	start = i;
	end = ft_strlen(s1);
	while (end > 0 && ft_strchr(set, s1[end - 1]))
		end--;
	return (ft_substr(s1, start, (end - start)));
}
/*
int main (void)
{
	char	set[];
	char	str[];
	char	*trimmed;

	set[] = "ka";
	str[] = "ka ya ka";
	trimmed = ft_strtrim(str,  set);
	if (trimmed != NULL)
	{
		printf("%s\n", trimmed);
		free (trimmed);
	}
	return (0);
}
*/