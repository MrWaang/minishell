/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbosviel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 04:57:12 by tbosviel          #+#    #+#             */
/*   Updated: 2024/11/01 02:16:56 by tbosviel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_u(unsigned int d)
{
	int	a;
	int	x;

	x = 0;
	if (d == 0)
		return (write(1, "0", 1));
	if (d / 10 != 0)
		x += ft_printf_d(d / 10);
	a = d % 10 + 48;
	return (write(1, &a, 1) + x);
}
