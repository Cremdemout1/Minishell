/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno <bruno@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 09:27:40 by yohan             #+#    #+#             */
/*   Updated: 2024/07/10 20:30:57 by bruno            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	end_of_str(int nb)
{
	int	len;

	len = 1;
	if (nb < 0)
		len++;
	while (nb / 10 != 0)
	{
		len++;
		nb /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		end;
	int		sign;
	char	*dest;

	sign = 1;
	end = end_of_str(n);
	dest = (char *)malloc((end + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	if (n < 0)
		sign = -1;
	dest[end] = '\0';
	while (end--)
	{
		dest[end] = (n % 10) * sign + 48;
		n /= 10;
	}
	if (sign == -1)
		dest[0] = '-';
	return (dest);
}
/*
int	main(void)
{
	char	*str1;
	char	*str2;
	char	*str3;
	char	*str4;
	int		i;
	char	*ptr;

	str1 = ft_itoa(2147483647);
	str2 = ft_itoa(-2147483648);
	str3 = ft_itoa(0);
	str4 = ft_itoa(10);
	printf("%s\n", str1);
	printf("%s\n", str2);
	printf("%s\n", str3);
	printf("%s\n", str4);
	i = -21;
	while (i < 100)
	{
		ptr = ft_itoa(i);
		printf("%s\n", ptr);
		free(ptr);
		i++;
	}
	free(str1);
	free(str2);
	free(str3);
	free(str4);
	return (0);
}
*/
