/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_numbers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno <bruno@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:05:38 by ycantin           #+#    #+#             */
/*   Updated: 2024/09/04 19:11:49 by bruno            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_putdecvalue(unsigned int nbr, int *len)
{
	if (nbr > 9)
		ft_putdecvalue(nbr / 10, len);
	ft__printf_putchar(nbr % 10 + '0', len);
}

void	ft_lowerhex(unsigned int nbr, int *len)
{
	int					i;
	unsigned int		basevalue;
	char				*base;

	i = 0;
	basevalue = 0;
	base = "0123456789abcdef";
	if (nbr == 0)
	{
		ft__printf_putchar('0', len);
		return ;
	}
	while (base[basevalue])
		basevalue++;
	if (nbr >= basevalue)
		ft_lowerhex(nbr / basevalue, len);
	while (base[i] && base[i] != base[nbr % basevalue])
		i++;
	write(1, &base[i], 1);
	(*len)++;
}

void	ft_upperhex(unsigned int nbr, int *len)
{
	int					i;
	unsigned int		basevalue;
	char				*base;

	i = 0;
	basevalue = 0;
	base = "0123456789ABCDEF";
	if (nbr == 0)
	{
		ft__printf_putchar('0', len);
		return ;
	}
	while (base[basevalue])
		basevalue++;
	if (nbr >= basevalue)
		ft_upperhex(nbr / basevalue, len);
	while (base[i] && base[i] != base[nbr % basevalue])
		i++;
	write(1, &base[i], 1);
	(*len)++;
}

void	ft_printaddress(size_t value, int *len)
{
	char	*str;
	int		i;

	str = "0123456789abcdef";
	i = 0;
	value = (unsigned long)value;
	if (value >= 16)
	{
		ft_printaddress(value / 16, len);
		ft_printaddress(value % 16, len);
	}
	else
	{
		i = value;
		write(1, &str[i], 1);
		(*len)++;
	}
}

void	ft_printwholeaddress(size_t values, int *len)
{
	if ((void *)values == 0)
	{
		write (1, "(nil)", 5);
		(*len) += 5;
		return ;
	}
	write(1, "0x", 2);
	(*len) += 2;
	ft_printaddress(values, len);
}
