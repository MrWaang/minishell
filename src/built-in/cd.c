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

void	update_oldpwd(char **env)
{
	int		i;
	char	*pwd;

	i = 0;
	pwd = NULL;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PWD", first_occurrence(env[i], '=')) == 0)
			pwd = ft_strdup(env[i]);
		if (pwd != NULL && ft_strncmp(env[i], "OLDPWD", first_occurrence(env[i],
					'=')) == 0)
		{
			free(env[i]);
			env[i] = NULL;
			env[i] = ft_strjoin("OLD", pwd);
		}
		i++;
	}
	free(pwd);
	return ;
}

void	update_pwd(char **env)
{
	int		i;
	char	cwd[100];//FIX je sais pas 
	char	*pwd;

	i = 0;
	update_oldpwd(env);
	while (env[i])
	{
		if (ft_strncmp(env[i], "PWD", first_occurrence(env[i], '=')) == 0)
		{
			pwd = getcwd(cwd, 100);
			free(env[i]);
			env[i] = NULL;
			env[i] = ft_strjoin("PWD=", pwd);
		}
		i++;
	}
	return ;
}

char	*find_var(char **env, char *name)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], name, first_occurrence(env[i], '=')) == 0)
			return (env[i]);
		i++;
	}
	return (NULL);
}

int	ft_cd(char **env, char *path)
{
	if (path == NULL && getenv("HOME") != NULL)
	{
		chdir(getenv("HOME"));
		update_pwd(env);
		return (0);
	}
	if (chdir(path) == -1)
	{
		write(2, "cd: no such file or directory:", 30);
		write(2, path, ft_strlen(path));
		return (1);
	}
	update_pwd(env);
	return (0);
}
