/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mah-ming <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 15:17:06 by mah-ming          #+#    #+#             */
/*   Updated: 2025/07/16 15:17:30 by mah-ming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static t_cmd *parse_single_command(t_token **tokens)
{
    t_cmd *cmd;

    cmd = create_cmd();
    if (!cmd)
        return (NULL);
    if (collect_arguments(cmd, tokens) == -1)
    {
        free_cmd(cmd);
        return (NULL);
    }
    finalize_cmd_args(cmd);
    return (cmd);
}

static int handle_pipe(t_token **tokens, t_cmd **last_cmd)
{
    t_cmd *new_cmd;

    advance_token(tokens);
    new_cmd = parse_single_command(tokens);
    if (!new_cmd)
        return (-1);
    link_commands(*last_cmd, new_cmd);
    *last_cmd = new_cmd;
    return (0);
}

static t_cmd *build_cmd_list(t_token *tokens)
{
    t_cmd *head;
    t_cmd *last_cmd;
    t_token *current;

    current = tokens;
    head = parse_single_command(&current);
    if (!head)
        return (NULL);
    last_cmd = head;
    while (current && current->type != TOKEN_EOF)
    {
        if (current->type == TOKEN_PIPE)
        {
            if (handle_pipe(&current, &last_cmd) == -1)
            {
                free_cmd_list(head);
                return (NULL);
            }
        }
        else
            current = current->next;
    }
    return (head);
}

t_cmd *parse_tokens(t_token *tokens)
{
    if (!tokens || tokens->type == TOKEN_EOF)
        return (NULL);
    return (build_cmd_list(tokens));
}

void free_cmd_list(t_cmd *cmd)
{
    t_cmd *next;

    while (cmd)
    {
        next = cmd->next;
        free_cmd(cmd);
        cmd = next;
    }
}
