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

void	env_swap(char **env, int i)
{
	while (env[i + 1])
	{
		env[i] = env[i + 1];
		i++;
	}
	env[i] = NULL;
	free(env[i]);
}

int	first_occurrence(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

static int	ft_unset_args(char **env, char *arg)
{
	int	i;
	int	fails;

	i = 0;
	fails = 1;
	while (env[i])
	{
		if (ft_strncmp(env[i], arg, first_occurrence(env[i], '=')) == 0)
		{
			env_swap(env, i);
			fails = 0;
		}
		i++;
	}
	return (fails);
}

int	ft_unset(char **env, char **args)
{
	int	i;
	int	fails;

	i = 0;
	fails = 0;
	(void)env;
	while (args[i])
	{
		fails += ft_unset_args(env, args[i]);
		i++;
	}
	if (fails)
		return (1);
	return (0);
}
