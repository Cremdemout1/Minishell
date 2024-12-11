/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfernan <brfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 12:42:21 by yohan             #+#    #+#             */
/*   Updated: 2024/09/05 15:18:25 by brfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int input)
{
	if ((input >= 65 && input <= 90) || (input >= 97 && input <= 122))
		return (1);
	return (0);
}

int	ft_isalphaund(int input)
{
	if ((input >= 65 && input <= 90) || (input >= 97 && input <= 122)
		|| input == 95)
		return (1);
	return (0);
}
