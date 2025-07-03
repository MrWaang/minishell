/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbosviel <marvin@d42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 18:07:32 by tbosviel          #+#    #+#             */
/*   Updated: 2025/07/03 18:07:32 by tbosviel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	env_array(t_env *list)
{
	t_env_node	*tmp;
	int			i;

	i = 0;
	tmp = list->head;
	list->c_env = NULL;
	list->c_env = malloc(sizeof(char *) * (list->size + 1));
	if (!list->c_env)
		return ;
	while (tmp)
	{
		list->c_env[i] = ft_strdup(tmp->line);
		i++;
		tmp = tmp->next;
	}
	list->c_env[i] = NULL;
	return ;
}
