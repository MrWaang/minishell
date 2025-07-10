/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbosviel <marvin@d42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 18:07:32 by tbosviel          #+#    #+#             */
/*   Updated: 2025/07/03 18:07:32 by tbosviel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include <unistd.h>

void	env_array(t_env *list)
{
	t_env_node	*tmp;
	int			i;

	i = 0;
	tmp = list->head;
	list->c_env = malloc(sizeof(char *) * (list->size + 1));
	if (!list->c_env)
		return ;
	while (tmp)
	{
		list->c_env[i] = ft_strdup(tmp->line);
		i++;
		tmp = tmp->next;
	}
	list->c_env[i] = NULL;
	return ;
}

char	*is_expand(t_env *env, char *str)
{
	char	*tmp;
	char	*env_line;
	int		size;

	tmp = NULL;
	if (!str)
		return (NULL);
	env_line = find_var(env, str);
	if (!env_line)
		return (NULL);
	size = first_occurrence(env_line, '=') + 1;
	if (env_line)
		tmp = ft_strdup(env_line + size);
	return (tmp);
}

void dup_handler(t_data *data, int fd[2])
{
	if (data->blocks_pos != data->blocks )
		dup2(fd[1], STDOUT_FILENO);
	if (data->blocks_pos != 1)
		dup2(data->fd_tmp, STDIN_FILENO);
}

void ft_exec(t_data *data, char **cmd, char **env)
{
	int fd[2];
	int pid;

	pipe(fd);
	pid = fork();
	if (pid == 0)
	{
		dup_handler(data, fd);
		close(fd[1]);
		close(fd[0]);
		if (data->fd_tmp)
			close(data->fd_tmp);
		execve(find_cmd_path(cmd[0], env), cmd, env);
	}
	close(fd[1]);
	if (data->fd_tmp != -1)
		close(data->fd_tmp); 
	data->fd_tmp = fd[0];
	waitpid(pid, NULL, 0);
}
