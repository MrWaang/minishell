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

void	export_no_args(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		printf("declare -x %s\n", env[i]);
		i++;
	}
	return ;
}

void	append_to_env(char **env, char *arg, int env_size)
{
	int		j;
	char	*tmp;

	j = 0;
	tmp = ft_strdup(arg + first_occurrence(arg, '=') + 1);
	while (arg[j] != '+')
	{
		arg[j] = arg[j];
		j++;
	}
	arg[j] = '=';
	arg[j + 1] = '\0';
	j = 0;
	while (env[j])
	{
		if (ft_strncmp(env[j], arg, first_occurrence(arg, '+')) == 0)
		{
			env[j] = ft_strjoin(env[j], tmp);
			return ;
		}
		j++;
	}
	env[env_size] = ft_strjoin(arg, tmp);
	return ;
}

void	add_to_env(char **env, char *arg)
{
	int	i;

	i = 0;
	while (env[i])
		i++;
	if (arg[first_occurrence(arg, '=') - 1] == '+')
		append_to_env(env, arg, i);
	else
	{
		env[i] = ft_strdup(arg);
		env[i + 1] = NULL;
	}
	return ;
}

int	check_export_args(char **env, char **args)
{
	int	i;
	int	fail;
	int	j;

	j = 0;
	fail = 0;
	i = 0;
	while (args[i])
	{
		if (ft_isalpha(args[i][0]) == 0 && args[i][0] != '_')
		{
			fail = 1;
			write(2, "export: not an identifier: ", 27);
			write(2, args[i], ft_strlen(args[i]));
		}
		while (args[i][j])
		{
			if (ft_isalpha(args[i][j]) == 0 && args[i][j] != '_')
				
			j++;
		}
		j = 0;
		add_to_env(env, args[i]);
		i++;
	}
	return (fail);
}

int	ft_export(char **env, char **args)
{
	int	fail;

	fail = 0;
	if (args[0] == NULL)
		export_no_args(env);
	else
		fail = check_export_args(env, args);
	return (fail);
}
