/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mah-ming <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 18:19:12 by tbosviel          #+#    #+#             */
/*   Updated: 2025/06/05 18:50:46 by mah-ming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	update_oldpwd(char **env)
{
	int		i;
	char	*pwd;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PWD", first_occurrence(env[i], '=')) == 0)
			pwd = ft_strdup(env[i]);
		if (ft_strncmp(env[i], "OLDPWD", first_occurrence(env[i], '=')) == 0)
		{
			env[i] = ft_strjoin("OLD", pwd);
		}
		i++;
	}
	return ;
}

void	update_pwd(char **env)
{
	int		i;
	char	cwd[100];
	char	*pwd;

	i = 0;
	update_oldpwd(env);
	while (env[i])
	{
		if (ft_strncmp(env[i], "PWD", first_occurrence(env[i], '=')) == 0)
		{
			pwd = getcwd(cwd, 100);
			env[i] = ft_strjoin("PWD=", pwd);
		}
		i++;
	}
	return ;
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
