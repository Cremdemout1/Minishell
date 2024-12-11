/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfernan <brfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 16:51:43 by ycantin           #+#    #+#             */
/*   Updated: 2024/08/20 19:06:07 by brfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *str, size_t nb)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *)str;
	while (i < nb)
	{
		ptr[i] = 0;
		i++;
	}
}

/* int main (void)
{
	char	x = "hello my friend";
	ft_bzero(x, 5);
	printf("%s\n", NULL);
	bzero(x, 5);
	printf("%s\n", x);
	return (0);
} */
