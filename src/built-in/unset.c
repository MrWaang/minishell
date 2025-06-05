/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mah-ming <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 18:37:21 by tbosviel          #+#    #+#             */
/*   Updated: 2025/06/04 21:07:55 by mah-ming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	ft_unset_args(char **env, char *arg)
{
	int	i;
	int	fails;

	i = 0;
	fails = 1;
	while (env[i])
	{
		if (ft_strncmp(env[i], arg, ft_strlen(arg)) == 0)
		{
			env[i] = "\0";
			fails = 0;
		}
		i++;
	}
	return (fails);
}

// unset == 0 if succesfull / == 1 if its fail to unset
int	ft_unset(char **env, char **args)
{
	int	i;
	int	fails;

	i = 0;
	fails = 0;
	while (args[i])
	{
		fails += ft_unset_args(env, args[i]);
		i++;
	}
	printf("%d", fails);
	return (fails);
}
