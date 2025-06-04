/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbosviel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 04:57:21 by tbosviel          #+#    #+#             */
/*   Updated: 2024/11/01 02:16:58 by tbosviel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	power(size_t nb, int e)
{
	if (e == 0)
		return (1);
	else
		return (nb * power(nb, e - 1));
}

int	ft_printf_x(unsigned int nb)
{
	char	*base;
	int		i;
	char	a;
	int		count;

	if (nb == 0)
		return (write(1, "0", 1));
	i = 7;
	count = 0;
	base = "0123456789abcdef";
	while (i >= 0)
	{
		a = base[(nb / power(16, i)) % 16];
		if ((nb / power(16, i)) > 0)
		{
			write(1, &a, 1);
			count++;
		}
		i--;
	}
	return (count);
}
