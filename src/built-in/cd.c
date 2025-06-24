/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mah-ming <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 18:19:12 by tbosviel          #+#    #+#             */
/*   Updated: 2025/06/10 05:53:39 by tbosviel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	update_oldpwd(t_env *env)
{
	char		*pwd;
	t_env_node	*tmp;

	pwd = NULL;
	tmp = env->head;
	while (tmp)
	{
		if (ft_strncmp(tmp->line, "PWD", first_occurrence(tmp->line, '=')) == 0)
		{
			pwd = ft_strdup(tmp->line);
			if (pwd == NULL)
				exit(1);
		}
		if (ft_strncmp(tmp->line, "OLDPWD", first_occurrence(tmp->line,
					'=')) == 0)
		{
			free(tmp->line);
			tmp->line = NULL;
			tmp->line = ft_strjoin("OLD", pwd);
			if (!tmp->line)
				exit(1);
		}
		tmp = tmp->next;
	}
	free(pwd);
	return ;
}

void	update_pwd(t_env *env)
{
	char		*pwd;
	t_env_node	*tmp;

	char cwd[100]; // FIX je sais pas
	tmp = env->head;
	update_oldpwd(env);
	while (tmp)
	{
		if (ft_strncmp(tmp->line, "PWD", first_occurrence(tmp->line, '=')) == 0)
		{
			pwd = getcwd(cwd, 100);
			free(tmp->line);
			tmp->line = NULL;
			tmp->line = ft_strjoin("PWD=", pwd);
			if (!tmp->line)
				exit(1);
		}
		tmp = tmp->next;
	}
	return ;
}

char	*find_var(t_env *env, char *name)
{
	t_env_node	*tmp;

	tmp = env->head;
	while (tmp)
	{
		if (ft_strncmp(tmp->line, name, first_occurrence(tmp->line, '=')) == 0)
			return (tmp->line);
		tmp = tmp->next;
	}
	return (NULL);
}

int	ft_cd(t_env *env, char *path)
{
	if (path == NULL && getenv("HOME") != NULL)
	{
		chdir(getenv("HOME"));
		update_pwd(env);
		return (0);
	}
	if (chdir(path) == -1)
	{
		write(2, "cd: no such file or directory", 29);
		return (1);
	}
	update_pwd(env);
	return (0);
}
