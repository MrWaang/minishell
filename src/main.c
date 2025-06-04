/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mah-ming <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 18:37:25 by tbosviel          #+#    #+#             */
/*   Updated: 2025/06/04 23:38:10 by mah-ming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../includes/builtins.h"

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
	char *test1[] = {"echo", "-nnnn", "Hello", NULL};

    ft_echo(test1);
	return (0);
}
