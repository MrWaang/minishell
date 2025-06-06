/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mah-ming <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 18:37:25 by tbosviel          #+#    #+#             */
/*   Updated: 2025/06/05 18:54:18 by mah-ming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/builtins.h"
#include "../includes/minishell.h"

int	main(int ac, char **av, char **env)
{
	int		i;
	int		j;
	int		env_size;
	char	**test;
	char	**env_test;

	i = 1;
	j = 0;
	env_size = 0;
	test = malloc(sizeof(char *) * ac);
	while (env[env_size])
		env_size++;
	env_test = malloc(sizeof(char *) * env_size);
	while (j < env_size)
	{
		env_test[j] = ft_strdup(env[j]);
		j++;
	}
	env_test[j] = NULL;
	while (av[i])
	{
		test[i - 1] = ft_strdup(av[i]);
		i++;
	}
	(void)ac;
	(void)av;
	(void)env;
	i = 0;
	i = ft_unset(env_test, test);
	while (env_test[i])
	{
		printf("%s\n", env_test[i]);
		i++;
	}
	return (0);
}
