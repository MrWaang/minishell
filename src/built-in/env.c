/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mah-ming <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 18:37:06 by tbosviel          #+#    #+#             */
/*   Updated: 2025/06/06 19:56:55 by mah-ming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_env(char **env)
{
    int	i;

	i = 0;
	if (!env)
		return (1);
	while(env[i])
	{
		printf("%s\n", env[i]);
		i++;
	}
	return (0);
}

int env_size(char **c_env)
{
	int size;

	size = 0;
	while (c_env && c_env[size])
		size++;
	return (size);
}

char **cpy_env(char **c_env)
{
	char **new_env;
	int size;
	int i;

	i = 0;
	size = env_size(c_env);
	new_env = malloc(sizeof(char *) * (size + 1));
	if (!new_env)
		return (NULL);
	while (i < size)
	{
		new_env[i] = ft_strdup(c_env[i]);
		if (!new_env[i])
		{
			free_array(new_env);
			return NULL;
		}
		i++;
	}
	new_env[i] = NULL;
	return (new_env);
}

t_env *init_env(char **c_env)
{
	t_env *env;

	env = malloc(sizeof(t_env));
	if (!env)
		return (NULL);
	env->c_env = cpy_env(c_env);
	if (!env->c_env)
	{
		free(env);
		return (NULL);
	}
	return (env);
}

void free_env(t_env *env)
{
	if (!env)
		return ;
	free_array(env->c_env);
	free(env);
}
