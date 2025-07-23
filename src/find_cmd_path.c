/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cmd_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbosviel <marvin@d42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 12:41:56 by tbosviel          #+#    #+#             */
/*   Updated: 2025/06/27 12:41:56 by tbosviel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*test_paths(char *cmd, char **paths)
{
	char	*cmd_path;
	char	*tmp;
	int		i;

	i = 0;
	cmd_path = NULL;
	tmp = NULL;
	while (paths[i])
	{
		tmp = ft_strjoin(paths[i], "/");
		cmd_path = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(cmd_path, X_OK) == 0)
			return (cmd_path);
		free(cmd_path);
		i++;
	}
	return (NULL);
}

void	free_paths(char **paths)
{
	int	i;

	i = 0;
	while (paths[i])
	{
		free(paths[i]);
		i++;
	}
	free(paths);
}

char	*find_cmd_path(char *cmd, char **env)
{
	char	**paths;
	char	*cmd_path;
	int		i;

	i = 0;
	paths = NULL;
	cmd_path = NULL;
	if (access(cmd, X_OK) == 0)
		return (strdup(cmd));
	while (env[i] && strncmp(env[i], "PATH=", 5) != 0)
		i++;
	if (!env[i])
		return (NULL);
	paths = ft_split(env[i] + 5, ':');
	cmd_path = test_paths(cmd, paths);
	free_paths(paths);
	return (cmd_path);
}
