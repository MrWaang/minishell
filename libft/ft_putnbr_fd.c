/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbosviel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 02:34:50 by tbosviel          #+#    #+#             */
/*   Updated: 2024/10/26 01:27:41 by tbosviel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	power(int nb, int e)
{
	if (e == 0)
		return (1);
	else
		return (nb * power(10, e - 1));
}

void	ft_putnbr_fd(int nb, int fd)
{
	char	a;
	int		i;

	i = 10;
	if (nb == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (nb == 0)
		write(fd, "0", 1);
	if (nb < 0)
	{
		nb = nb * (-1);
		write(fd, "-", 1);
	}
	while (i-- > 0)
	{
		a = (nb / power(10, i)) % 10 + 48;
		if ((nb / power(10, i)) > 0)
			write(fd, &a, 1);
	}
}
