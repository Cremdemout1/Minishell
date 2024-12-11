/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_even.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno <bruno@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 11:48:58 by bruno             #+#    #+#             */
/*   Updated: 2024/07/01 15:52:23 by bruno            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_is_even(int n)
{
	if (n % 2 == 0)
		return (true);
	else
		return (false);
}

bool	ft_is_odd(int n)

{
	if (n % 2 == 0)
		return (false);
	else
		return (true);
}
