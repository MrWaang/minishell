/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mah-ming <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 18:37:25 by tbosviel          #+#    #+#             */
/*   Updated: 2025/06/11 19:16:47 by mah-ming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include <libft/ft_printf.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	main(int ac, char **av, char **env)
{
	char	**args;
	t_env	*c_env;
	int		i;

	i = 1;
	(void)ac;
	(void)env;
	c_env = create_env_list(env);
	if (!env)
		printf("Erreur init_env");
	args = malloc(sizeof(char *) * ac);
	while (av[i])
	{
		args[i - 1] = ft_strdup(av[i]);
		i++;
	}
	args[i - 1] = NULL;
	// if (is_built_in(cmd) == 1)
	// {
		// built_in_headler(cmd, args, c_env);
	// }
	// ft_env(c_env);
	// char *path = find_cmd_path(args[0], env);
	// if (path)
	// {
		// printf("%s", path);
		// free(path);
	// }
	// t_data *data;
	// data = malloc(sizeof(t_data));
	// data->fd_tmp = -1;
	// char *arg[] = {"grep", "^d", NULL};
	// char *arg2[] = {"wc", "-l", NULL};
	// data->blocks = 3;
	// data->blocks_pos = 1;
	// ft_exec(data, args, env);
	// data->blocks_pos = 2;
	// ft_exec(data, arg, env);
	// data->blocks_pos = 3;
	// ft_exec(data, arg2, env);
	// close(data->fd_tmp);
	// free(data);
	heredoc(args[0]);
	i -= 1;
	while (i >= 0)
	{
		free(args[i]);
		i--;
	}
	free(args);
	free_env_list(c_env);
	return (0);
}
