/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbosviel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 04:56:38 by tbosviel          #+#    #+#             */
/*   Updated: 2024/11/01 02:16:53 by tbosviel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	hexadress(size_t adress, char *base)
{
	size_t	count;

	count = 0;
	if (adress >= 16)
	{
		count += hexadress(adress / 16, base);
	}
	if ((adress % 16) < 10)
		count += write(1, &base[adress % 16], 1);
	else
		count += write(1, &base[adress % 16], 1);
	return (count);
}

int	ft_printf_p(void *adress)
{
	char	*base;

	if (!adress)
		return (write(1, "(nil)", 5));
	base = "0123456789abcdef";
	write(1, "0x", 2);
	return (2 + hexadress((size_t)adress, base));
}
