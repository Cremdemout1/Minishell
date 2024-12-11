/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno <bruno@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 12:39:01 by ycantin           #+#    #+#             */
/*   Updated: 2024/09/04 19:27:07 by bruno            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <stdio.h>
# include <unistd.h>
# include "libft.h"

int		ft_printf(const char *str, ...);
int		ft_printf_fd(int fd, const char *str, ...);
void	ft_printcommands(char c, va_list *conversions, int *len, int *i);
void	ft__printf_putchar(char c, int *len);
void	ft_printf_putstr(char *str, int *len);
void	ft_printf_putnbr(int nbr, int *len);
void	ft_putdecvalue(unsigned int nbr, int *len);
void	ft_lowerhex(unsigned int nbr, int *len);
void	ft_upperhex(unsigned int nbr, int *len);
void	ft_printwholeaddress(size_t pointer, int *len);

#endif