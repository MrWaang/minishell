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
	int	m;

	n = first_occurrence(env, c);
	m = first_occurrence(arg, c);
	if (ft_strncmp(env, arg, n) == 0 && n == m)
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

int	is_built_in(char *cmd)
{
	if (!ft_strncmp("cd ", cmd, 3) || !ft_strncmp("pwd ", cmd, 4)
		|| !ft_strncmp("env ", cmd, 4) || !ft_strncmp("exit ", cmd, 5)
		|| !ft_strncmp("echo ", cmd, 5) || !ft_strncmp("unset ", cmd, 6)
		|| !ft_strncmp("export ", cmd, 7))
		return (1);
	return (0);
}

int	built_in_handler(char *cmd, char **args, t_env *env)
{
	int	value;

	value = 0;
	if (!ft_strncmp("cd ", cmd, 3))
		value = ft_cd(env, args[0]);
	else if (!ft_strncmp("pwd ", cmd, 4))
		value = ft_pwd();
	else if (!ft_strncmp("env ", cmd, 4))
		value = ft_env(env);
	else if (!ft_strncmp("exit ", cmd, 5))
		value = ft_exit(args); // FIX free tout avant d'exit
	else if (!ft_strncmp("echo ", cmd, 5))
		value = ft_echo(args);
	else if (!ft_strncmp("unset ", cmd, 6))
		value = ft_unset(env, args);
	else if (!ft_strncmp("export ", cmd, 7))
		value = ft_export(env, args);
	return (value);
}

