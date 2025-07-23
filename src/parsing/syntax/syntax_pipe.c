/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_pipe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mah-ming <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 00:08:41 by mah-ming          #+#    #+#             */
/*   Updated: 2025/07/16 15:11:18 by mah-ming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int is_pipe_at_start(t_token *tokens)
{
    if (!tokens)
        return (0);
    if (tokens->type == TOKEN_PIPE)
        return (1);
    return (0);
}

int is_pipe_at_end(t_token *tokens)
{
    t_token *current;
    t_token *last_meaningful;

    current = tokens;
    last_meaningful = NULL;
    while (current && current->type != TOKEN_EOF)
    {
        if (current->type != TOKEN_WORD || ft_strlen(current->value) > 0)
            last_meaningful = current;
        current = current->next;
    }
    if (last_meaningful && last_meaningful->type == TOKEN_PIPE)
        return (1);
    return (0);
}

int has_consecutive_pipes(t_token *tokens)
{
    t_token *current;
    t_token *next;

    current = tokens;
    while (current && current->type != TOKEN_EOF)
    {
        if (current->type == TOKEN_PIPE)
        {
            next = get_next_meaningful_token(current->next);
            if (next && next->type == TOKEN_PIPE)
                return (1);
        }
        current = current->next;
    }
    return (0);
}

int has_empty_pipe(t_token *tokens)
{
    t_token *current;
    t_token *next;

    current = tokens;
    while (current && current->type != TOKEN_EOF)
    {
        if (current->type == TOKEN_PIPE)
        {
            next = get_next_meaningful_token(current->next);
            if (!next || next->type == TOKEN_EOF || next->type == TOKEN_PIPE)
                return (1);
        }
        current = current->next;
    }
    return (0);
}

int check_pipe_errors(t_token *tokens)
{
    if (is_pipe_at_start(tokens))
        return (set_syntax_error("|"));
    if (is_pipe_at_end(tokens))
        return (set_syntax_error("|"));
    if (has_consecutive_pipes(tokens))
        return (set_syntax_error("|"));
    if (has_empty_pipe(tokens))
        return (set_syntax_error("|"));
    return (0);
}
