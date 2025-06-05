/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mah-ming <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 18:37:06 by tbosviel          #+#    #+#             */
/*   Updated: 2025/06/05 22:49:51 by mah-ming         ###   ########.fr       */
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
		printf("%s/n", env[i]);
		i++;
	}
	return (0);
}

int env_size(char **env_d)
{
	int size;

	size = 0;
	while (env_d && env_d[size])
		size++;
	return (size);
}
