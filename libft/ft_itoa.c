/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbosviel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 01:13:46 by tbosviel          #+#    #+#             */
/*   Updated: 2024/10/17 07:38:15 by tbosviel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_calloc(size_t count, size_t size);

static int	ft_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	else
		return (nb * ft_power(nb, power - 1));
}

static char	*ft_itoa2(int n, char *str, size_t j)
{
	size_t	i;

	i = 1;
	while (i <= 10)
	{
		if ((n / ft_power(10, 10 - i)) != 0)
		{
			str[j] = (n / ft_power(10, 10 - i)) % 10 + 48;
			j++;
		}
		i++;
	}
	str[j] = '\0';
	return (str);
}

static int	len_n(int n)
{
	size_t	i;

	i = 0;
	if (n < 0)
	{
		i++;
		n = -n;
	}
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	j;

	j = 0;
	if (n == -2147483648)
	{
		return (ft_strdup("-2147483648"));
	}
	if (n == 0)
	{
		return (ft_strdup("0"));
	}
	str = ft_calloc(len_n(n) + 1, sizeof(char));
	if (str == 0)
		return (NULL);
	if (n < 0)
	{
		n = -n;
		str[j++] = '-';
	}
	return (ft_itoa2(n, str, j));
}
