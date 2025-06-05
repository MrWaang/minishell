/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mah-ming <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 18:37:06 by tbosviel          #+#    #+#             */
/*   Updated: 2025/06/05 18:54:19 by mah-ming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void    ft_env(char **env)
{
    int        i;
    char    *path;

    i = 0;
    path = getenv("PATH");
    if (!path)
    {
        printf("zsh: command not found: env\n");
        return ;
    }
    while (env[i])
    {
        printf("%s\n", env[i]);
        i++;
    }
    return ;
}
