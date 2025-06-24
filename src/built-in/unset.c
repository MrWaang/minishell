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

void	env_del(t_env *env, int i)
{
	t_env_node	*tmp;
	t_env_node	*prev;
	int			j;

	j = 0;
	tmp = env->head;
	prev = NULL;
	while (j < i)
	{
		prev = tmp;
		tmp = tmp->next;
		j++;
	}
	if (j == 0)
		env->head = tmp->next;
	else if (j == env->size - 1)
		prev->next = NULL;
	else
		prev->next = tmp->next;
	free(tmp->line);
	free(tmp);
}

static int	ft_unset_args(t_env *env, char *arg)
{
	int			i;
	t_env_node	*tmp;
	int			fails;

	tmp = env->head;
	i = 0;
	fails = 1;
	while (tmp)
	{
		if (ft_strncmp(tmp->line, arg, first_occurrence(tmp->line, '=')) == 0
			&& (first_occurrence(tmp->line, '=') == first_occurrence(arg, '=')))
		{
			env_del(env, i);
			env->size -= 1;
			fails = 0;
			return (0);
		}
		i++;
		tmp = tmp->next;
	}
	return (fails);
}

int	ft_unset(t_env *env, char **args)
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
	if (fails)
	{
		return (1);
		printf("bah gros noob");
	}
	return (0);
}
