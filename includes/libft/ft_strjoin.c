/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfernan <brfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 12:43:06 by yohan             #+#    #+#             */
/*   Updated: 2024/08/20 19:23:34 by brfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*full;

	j = 0;
	i = 0;
	full = malloc((ft_strlen(s1) + ft_strlen(s2)) + 1 * sizeof(char));
	if (full == NULL)
		return (NULL);
	while (s1 && s1[i])
	{
		full[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
	{
		full[i] = s2[j];
		i++;
		j++;
	}
	full[i] = '\0';
	return (full);
}

char	*ft_strjoin3(char const *s1, char const *s2, char const *s3)
{
	int		i;
	int		j;
	int		k;
	char	*full;

	i = -1;
	j = 0;
	k = 0;
	full = ft_calloc((ft_strlen(s1)
				+ ft_strlen(s2) + ft_strlen(s3)) + 1, sizeof(char));
	if (full == NULL)
		return (NULL);
	while (s1 && s1[++i])
		full[i] = s1[i];
	while (s2 && s2[j])
		full[i++] = s2[j++];
	while (s3 && s3[k])
		full[i++] = s3[k++];
	full[i] = '\0';
	return (full);
}
/* 
int main (int argc, char *argv[])
{
	if (argc != 4)
		return (0);
	else
	{
		printf("%s", ft_strjoin3(argv[1], argv[2], argv[3]));
		return (0);
	}
}
 */