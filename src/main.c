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

int	main(int ac, char **av, char **env)
{
	t_env *c_env;
	char **args;
	int i;

	i = 1;
	args = malloc(sizeof(char *) * ac);
	while(av[i])
	{
		args[i - 1] = ft_strdup(av[i]);
		i++;
	}
	args[i - 1] = NULL;
	(void)ac;
	(void)av;
	c_env = create_env_list(env);
	if (!env)
		printf("Erreur init_env");
	ft_export(c_env->c_env, args);
	ft_env(c_env);
	// printf("\n\n\n HOME = %s\n", getenv("HOME"));
	// printf("\n USER = %s\n", getenv("USER"));
	// printf("\n SHELL = %s\n", getenv("SHELL"));
	i -= 1;
	while(i >= 0)
	{
		free(args[i]);
		i--;
	}
	free (args);
	free_env(c_env);
	return (0);
}
