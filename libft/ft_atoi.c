/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbosviel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 00:01:16 by tbosviel          #+#    #+#             */
/*   Updated: 2024/10/15 01:41:48 by tbosviel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	test_nbr(int state, int nbr)
{
	if (state % 2 == 1)
		return (-nbr);
	else
		return (nbr);
}

int	ft_atoi(const char *str)
{
	int	state;
	int	i;
	int	nbr;

	nbr = 0;
	i = 0;
	state = 0;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n' || str[i] == '\r'
		|| str[i] == '\t' || str[i] == '\v')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			state++;
		i++;
	}
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10 + str[i] - 48;
		if (!(str[i + 1] >= '0' && str[i + 1] <= '9'))
			return (test_nbr(state, nbr));
		i++;
	}
	return (0);
}
