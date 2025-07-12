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

void	create_oldpwd(t_env *env, char *pwd)
{
	char		*oldpwd;
	t_env_node	*tmp;

	oldpwd = ft_strjoin("OLD", pwd);
	tmp = create_node(oldpwd);
	if (!tmp)
		exit(1);
	free(oldpwd);
	add_node_to_list(env, tmp);
	env->size++;
}

void	update_oldpwd(t_env *env)
{
	char		*pwd;
	int			here;
	t_env_node	*tmp;

	here = 0;
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
			here = 1;
		}
		tmp = tmp->next;
	}
	if (here == 0)
		create_oldpwd(env, pwd);
	free(pwd);
	return ;
}

void	update_pwd(t_env *env)
{
	char		*pwd;
	t_env_node	*tmp;
	char		cwd[PATH_MAX + 1];

	tmp = env->head;
	update_oldpwd(env);
	while (tmp)
	{
		if (its_env(tmp->line, "PWD", '=') == 0)
		{
			pwd = getcwd(cwd, PATH_MAX + 1);
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
	if (path == NULL && find_var(env, "HOME") != NULL)
	{
		chdir(getenv("HOME"));
		if (find_var(env, "PWD") != NULL)
			update_pwd(env);
		else if (find_var(env, "OLDPWD") != NULL)
			ft_unset_args(env, find_var(env, "OLDPWD"));
		return (0);
	}
	if (path == NULL)
		return (1);
	if (chdir(path) == -1)
	{
		write(2, "cd: no such file or directory", 29);
		return (1);
	}
	if (find_var(env, "PWD") != NULL)
		update_pwd(env);
	else if (find_var(env, "OLDPWD") != NULL)
		ft_unset_args(env, find_var(env, "OLDPWD"));
	return (0);
}
