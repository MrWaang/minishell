/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mah-ming <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 14:53:02 by mah-ming          #+#    #+#             */
/*   Updated: 2025/06/23 18:28:15 by mah-ming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void free_array(char **array)
{
	int i;

	i = 0;
	if (!array)
		return;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void free_env_list(t_env *env)
{
	t_env_node *main;
	t_env_node *next;

	if (!env)
		return;
	main = env->head;
	while (main)
	{
		next = main->next;
		free(main->line);
		free(main);
		main = next;
	}
}

void free_token_list(t_token *head)
{
	t_token *main;
	t_token *next;

	main = head;
	while (main)
	{
		next = main->next;
		if (main->value)
			free(main->value);
		free(main);
		main = next;
	}
}
