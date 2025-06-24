/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mah-ming <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 14:53:02 by mah-ming          #+#    #+#             */
/*   Updated: 2025/06/11 19:17:26 by mah-ming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	first_occurrence(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

void	free_array(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return ;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	free_env_list(t_env *env)
{
	t_env_node	*main;
	t_env_node	*next;

	if (!env)
		return ;
	main = env->head;
	while (main)
	{
		next = main->next;
		free(main->line);
		free(main);
		main = next;
	}
	free(env);
}
