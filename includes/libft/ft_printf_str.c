/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno <bruno@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:57:18 by ycantin           #+#    #+#             */
/*   Updated: 2024/09/04 19:11:26 by bruno            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_printf_putstr(char *str, int *len)
{
	size_t	i;

	i = 0;
	if (str == 0)
	{
		write(1, "(null)", 6);
		(*len) += 6;
		return ;
	}
	while (str[i])
	{
		ft__printf_putchar(str[i], len);
		i++;
	}
}

void	ft__printf_putchar(char c, int *len)
{
	write(1, &c, 1);
	(*len)++;
}

void	ft_printf_putnbr(int nbr, int *len)
{
	if (nbr == -2147483648)
	{
		write(1, "-2147483648", 11);
		*len += 11;
		return ;
	}
	if (nbr < 0)
	{
		ft__printf_putchar('-', len);
		nbr *= -1;
	}
	if (nbr > 9)
	{
		ft_printf_putnbr(nbr / 10, len);
		ft_printf_putnbr(nbr % 10, len);
	}
	else
		ft__printf_putchar(nbr + '0', len);
}
