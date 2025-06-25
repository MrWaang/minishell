/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mah-ming <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 18:37:10 by tbosviel          #+#    #+#             */
/*   Updated: 2025/06/06 19:56:54 by mah-ming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	to_exit(long long int values)
{
	printf("exit\n");
	exit(values);
}

int	ft_exit(char **args)
{
	int	i;

	i = 0;
	if (args[0] == NULL)
		to_exit(0);
	while (args[0][i])
	{
		if (ft_isdigit(args[0][i]) == 0 && args[0][i] != '+'
			&& args[0][i] != '-')
		{
			printf("exit\n");
			write(2, "numeric argument required\n", 26);
			exit(255);
		}
		i++;
	}
	if (args[1])
	{
		printf("exit\n");
		write(2, "too many arguments\n", 19);
		return (1);
	}
	to_exit((unsigned char)ft_atoi(args[0]));
	return (0);
}
