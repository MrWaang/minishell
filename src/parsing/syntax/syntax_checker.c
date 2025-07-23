/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mah-ming <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 20:37:56 by mah-ming          #+#    #+#             */
/*   Updated: 2025/07/16 15:18:31 by mah-ming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static int check_first_token(t_token *tokens)
{
    if (!tokens || tokens->type == TOKEN_EOF)
        return (0);
    if (tokens->type == TOKEN_PIPE)
        return (set_syntax_error("|"));
    return (0);
}

static int check_last_meaningful_token(t_token *tokens)
{
    t_token *last;
    t_token *current;

    last = NULL;
    current = tokens;
    while (current && current->type != TOKEN_EOF)
    {
        if (current->type != TOKEN_WORD || ft_strlen(current->value) > 0)
            last = current;
        current = current->next;
    }
    if (last && is_operator(last->type))
        return (set_syntax_error("newline"));
    return (0);
}

static int validate_token_sequence(t_token *tokens)
{
    if (check_pipe_errors(tokens) != 0)
        return (1);
    if (check_redir_errors(tokens) != 0)
        return (1);
    return (0);
}

int has_syntax_error(t_token *tokens)
{
    if (check_first_token(tokens) != 0)
        return (1);
    if (check_last_meaningful_token(tokens) != 0)
        return (1);
    if (validate_token_sequence(tokens) != 0)
        return (1);
    return (0);
}

int check_syntax(t_token *tokens)
{
    if (!tokens)
        return (0);
    return (has_syntax_error(tokens));
}
