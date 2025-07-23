/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mah-ming <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 18:37:25 by tbosviel          #+#    #+#             */
/*   Updated: 2025/07/20 18:01:57 by mah-ming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// int g_last_exit_status;
// t_env *g_env;

int main(int argc, char **argv, char **envp)
{
    (void)argc;
    (void)argv;

    g_env = create_env_list(envp);
    if (!g_env)
    {
        write(2, "Failed to initialize environment\n", 33);
        return (1);
    }
    g_last_exit_status = 0;
    prompt();
    free_env_list(g_env);
    return (0);
}


