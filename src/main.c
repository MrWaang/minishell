/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mah-ming <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 18:37:25 by tbosviel          #+#    #+#             */
/*   Updated: 2025/06/06 19:56:50 by mah-ming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	t_env *c_env;

	c_env = init_env(env);
	if (!env)
		printf("Erreur init_env");
	ft_env(c_env->c_env);
	printf("\n\n\n HOME = %s\n", getenv("HOME"));
	printf("\n USER = %s\n", getenv("USER"));
	printf("\n SHELL = %s\n", getenv("SHELL"));
	free_env(c_env);
	return (0);
}
