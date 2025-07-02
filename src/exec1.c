/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbosviel <marvin@d42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 14:05:36 by tbosviel          #+#    #+#             */
/*   Updated: 2025/07/02 14:05:36 by tbosviel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	is_built_in(char *cmd)
{
	if (!ft_strncmp("cd ", cmd, 3) || !ft_strncmp("pwd ", cmd, 4)
		|| !ft_strncmp("env ", cmd, 4) || !ft_strncmp("exit ", cmd, 5)
		|| !ft_strncmp("echo ", cmd, 5) || !ft_strncmp("unset ", cmd, 6)
		|| !ft_strncmp("export ", cmd, 7))
		return (1);
	return (0);
}

int	built_in_headler(char *cmd, char **args, t_env *env)
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

void	redir_out(char *filename)
{
	int	fd;

	fd = 0;
	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	dup2(fd, STDOUT_FILENO);
	close(fd);
}

void	redir_out_append(char *filename)
{
	int	fd;

	fd = 0;
	fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0644);
	dup2(fd, STDOUT_FILENO);
	close(fd);
}
