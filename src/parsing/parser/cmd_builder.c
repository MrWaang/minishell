/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_builder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mah-ming <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 15:17:41 by mah-ming          #+#    #+#             */
/*   Updated: 2025/07/16 15:18:30 by mah-ming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

t_cmd *create_cmd(void)
{
    t_cmd *cmd;

    cmd = malloc(sizeof(t_cmd));
    if (!cmd)
        return (NULL);
    cmd->args = NULL;
    cmd->arg_count = 0;
    cmd->redirs = NULL;
    cmd->next = NULL;
    return (cmd);
}

void add_argument(t_cmd *cmd, char *arg)
{
    char **new_args;
    int i;

    if (!cmd || !arg)
        return;
    new_args = malloc(sizeof(char *) * (cmd->arg_count + 2));
    if (!new_args)
        return;
    i = 0;
    while (i < cmd->arg_count)
    {
        new_args[i] = cmd->args[i];
        i++;
    }
    new_args[i] = ft_strdup(arg);
    new_args[i + 1] = NULL;
    if (cmd->args)
        free(cmd->args);
    cmd->args = new_args;
    cmd->arg_count++;
}

void finalize_cmd_args(t_cmd *cmd)
{
    if (!cmd || !cmd->args)
        return;
    if (cmd->arg_count > 0 && cmd->args[cmd->arg_count] != NULL)
        cmd->args[cmd->arg_count] = NULL;
}

void link_commands(t_cmd *cmd1, t_cmd *cmd2)
{
    if (!cmd1 || !cmd2)
        return;
    cmd1->next = cmd2;
}

void free_cmd(t_cmd *cmd)
{
    int i;

    if (!cmd)
        return;
    if (cmd->args)
    {
        i = 0;
        while (cmd->args[i])
        {
            free(cmd->args[i]);
            i++;
        }
        free(cmd->args);
    }
    free_redir_list(cmd->redirs);
    free(cmd);
}
