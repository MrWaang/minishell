/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mah-ming <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 18:37:06 by tbosviel          #+#    #+#             */
/*   Updated: 2025/06/11 19:16:01 by mah-ming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_env(t_env *env)
{
	t_env_node	*main;

	if (!env || !env->head)
		return (1);
	main = env->head;
	while (main)
	{
		printf("%s\n", main->line);
		main = main->next;
	}
	return (0);
}

t_env_node	*create_node(char *line)
{
	t_env_node	*new_node;

	new_node = malloc(sizeof(t_env_node));
	if (!new_node)
		return (NULL);
	new_node->line = ft_strdup(line);
	if (!new_node->line)
	{
		free(new_node);
		return (NULL);
	}
	new_node->next = NULL;
	return (new_node);
}

void	add_node_to_list(t_env *env, t_env_node *new_node)
{
	t_env_node	*main;

	if (!env->head)
	{
		env->head = new_node;
		return ;
	}
	main = env->head;
	while (main->next != NULL)
		main = main->next;
	main->next = new_node;
}

t_env	*create_env_list(char **envt)
{
	t_env		*env;
	int			i;
	t_env_node	*node;

	env = malloc(sizeof(t_env));
	if (!env)
		return (NULL);
	env->head = NULL;
	env->size = 0;
	env->c_env = NULL;
	i = 0;
	while (envt[i])
	{
		node = create_node(envt[i]);
		if (!node)
		{
			free_env_list(env);
			return (NULL);
		}
		add_node_to_list(env, node);
		env->size++;
		i++;
	}
	return (env);
}
