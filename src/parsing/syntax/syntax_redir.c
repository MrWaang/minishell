/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_redir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mah-ming <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 19:44:42 by mah-ming          #+#    #+#             */
/*   Updated: 2025/07/16 15:11:16 by mah-ming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int is_redir_without_file(t_token *token)
{
    t_token *next;

    if (!token || !is_redirection(token->type))
        return (0);
    next = get_next_meaningful_token(token->next);
    if (!next || next->type == TOKEN_EOF || is_operator(next->type))
        return (1);
    return (0);
}

int has_consecutive_redirs(t_token *tokens)
{
    t_token *current;
    t_token *next;

    current = tokens;
    while (current && current->type != TOKEN_EOF)
    {
        if (is_redirection(current->type))
        {
            next = get_next_meaningful_token(current->next);
            if (next && is_redirection(next->type))
                return (1);
        }
        current = current->next;
    }
    return (0);
}

int is_valid_redir_target(t_token *token)
{
    t_token *next;

    if (!token || !is_redirection(token->type))
        return (1);
    next = token->next;
    if (!next || next->type != TOKEN_WORD)
        return (0);
    if (ft_strlen(next->value) == 0)
        return (0);
    return (1);
}

int check_heredoc_delimiter(t_token *token)
{
    t_token *next;

    if (!token || token->type != TOKEN_HEREDOC)
        return (0);
    next = token->next;
    if (!next || next->type != TOKEN_WORD || ft_strlen(next->value) == 0)
        return (1);
    return (0);
}

int check_redir_errors(t_token *tokens)
{
    t_token *current;
    char *error_token;

    current = tokens;
    while (current && current->type != TOKEN_EOF)
    {
        if (is_redirection(current->type))
        {
            if (is_redir_without_file(current))
            {
                error_token = "newline";
                return (set_syntax_error(error_token));
            }
            if (current->type == TOKEN_HEREDOC && check_heredoc_delimiter(current))
                return (set_syntax_error("newline"));
        }
        current = current->next;
    }
    if (has_consecutive_redirs(tokens))
    {
        current = tokens;
        while (current && current->type != TOKEN_EOF)
        {
            if (is_redirection(current->type))
            {
                t_token *next = get_next_meaningful_token(current->next);
                if (next && is_redirection(next->type))
                    return (set_syntax_error(next->value));
            }
            current = current->next;
        }
    }
    return (0);
}
