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
	char	**args;

	t_env	*c_env;
	int		i;
	i = 1;
	(void)ac;
	(void)av;
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
	ft_cd(c_env, args[0]);
	ft_env(c_env);
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
