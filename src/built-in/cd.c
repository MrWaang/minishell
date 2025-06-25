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

char	*get_pwd(t_env *env)
{
	t_env_node	*tmp;
	char		*pwd;

	pwd = NULL;
	tmp = env->head;
	while (tmp)
	{
		if (its_env(tmp->line, "PWD", '=') == 0)
		{
			pwd = ft_strdup(tmp->line);
			if (pwd == NULL)
				exit(1);
		}
		tmp = tmp->next;
	}
	return (pwd);
}

void	update_oldpwd(t_env *env)
{
	char		*pwd;
	t_env_node	*tmp;

	pwd = get_pwd(env);
	tmp = env->head;
	while (tmp)
	{
		if (pwd != NULL && its_env(tmp->line, "OLDPWD", '=') == 0)
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
		if (its_env(tmp->line, "PWD", '=') == 0)
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
