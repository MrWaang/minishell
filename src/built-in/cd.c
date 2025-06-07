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

void	update_oldpwd(char **env, char *pwd)
{
	int		i;
	char	*oldpwd;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "OLDPWD", first_occurrence(env[i], '=')) == 0)
		{
			oldpwd = ft_strjoin("OLDPWD=", pwd);
			// free(env[i]);
			env[i] = oldpwd;
		}
		i++;
	}
	// free(oldpwd);
	return ;
}

void	update_pwd(char **env, char *path)
{
	int		i;
	char	*oldpwd;
	char	*pwd;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PWD", first_occurrence(env[i], '=')) == 0)
		{
			oldpwd = ft_strdup(env[i] + 4);
			path = ft_strjoin("/", path);
			pwd = ft_strjoin(env[i], path);
			free(env[i]);
			env[i] = pwd;
		}
		i++;
	}
	update_oldpwd(env, oldpwd);
	// free(pwd);
	return ;
}

int	ft_cd(char **env, char *path)
{
	chdir(path);
	if (chdir(path) == -1)
	{
		write(2, "cd: no such file or directory:", 30);
		write(2, path, ft_strlen(path));
		return (1);
	}
	update_pwd(env, path);
	return (0);
}
