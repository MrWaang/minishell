/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mah-ming <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 18:37:14 by tbosviel          #+#    #+#             */
/*   Updated: 2025/06/04 21:07:58 by mah-ming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	add_to_env(t_env_node **lst, t_env_node *new)
{
	t_env_node	*tmp;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

void	replace_env(t_env *env, char *arg)
{
	t_env_node	*tmp;

	tmp = env->head;
	while (tmp)
	{
		if (ft_strncmp(tmp->line, arg, first_occurrence(tmp->line, '=')) == 0
			&& (first_occurrence(tmp->line, '=') == first_occurrence(arg, '=')))
		{
			free(tmp->line);
			tmp->line = NULL;
			tmp->line = ft_strdup(arg);
			if (tmp->line == NULL)
				exit(1);
			return ;
		}
		tmp = tmp->next;
	}
}

void	append_env(t_env *env, char *arg)
{
	t_env_node	*tmp;
	char		*old_tmp;

	tmp = env->head;
	ft_strccut(arg, '+');
	while (tmp)
	{
		if (ft_strncmp(tmp->line, arg, first_occurrence(tmp->line, '=')) == 0
			&& (first_occurrence(tmp->line, '=') == first_occurrence(arg, '=')))
		{
			old_tmp = tmp->line;
			tmp->line = ft_strjoin(tmp->line, arg + first_occurrence(arg, '=')
					+ 1);
			if (tmp->line == NULL)
				exit(1);
			free(old_tmp);
			old_tmp = NULL;
		}
		tmp = tmp->next;
	}
	return ;
}

int	export_headler(t_env *env, char *arg)
{
	t_env_node	*test;
	int			check;

	check = check_arg(env, arg);
	if (check == 0)
	{
		test = create_node(arg);
		if (test == NULL)
			exit(1);
		add_to_env(&env->head, test);
		env->size += 1;
	}
	else if (check < 0)
	{
		if (arg[first_occurrence(arg, '=') - 1] == '+')
			append_env(env, arg);
		else
			replace_env(env, arg);
	}
	else
	{
		perror("invalid argument");
		return (1);
	}
	return (0);
}

int	ft_export(t_env *env, char **args)
{
	int	i;
	int	fail;

	i = 0;
	fail = 0;
	while (args[i])
	{
		fail = export_headler(env, args[i]);
		i++;
	}
	return (fail);
}
