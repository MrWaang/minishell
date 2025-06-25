/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbosviel <marvin@d42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 09:49:40 by tbosviel          #+#    #+#             */
/*   Updated: 2025/06/25 09:49:40 by tbosviel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	its_env(char *env, char *arg, char c)
{
	int	n;

	n = first_occurrence(env, c);
	if (ft_strncmp(env, arg, n) == 0)
		return (0);
	return (1);
}

int	first_occurrence(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

char	*find_var(t_env *env, char *name)
{
	t_env_node	*tmp;

	tmp = env->head;
	while (tmp)
	{
		if (its_env(tmp->line, name, '=') == 0)
			return (tmp->line);
		tmp = tmp->next;
	}
	return (NULL);
}
