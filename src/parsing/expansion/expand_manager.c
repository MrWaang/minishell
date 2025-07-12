/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mah-ming <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 13:06:40 by mah-ming          #+#    #+#             */
/*   Updated: 2025/07/12 13:18:33 by mah-ming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static void expand_single_token(t_token *token, t_env *env, int last_exit_status)
{
    if (!should_expand_token(token))
        return;
    if (is_single_quoted(token->value))
    {
        process_quotes_in_token(token);
        return;
    }
    if (is_double_quoted(token->value))
    {
        process_quotes_in_token(token);
        expand_variables(&token->value, env, last_exit_status);
        return;
    }
    expand_variables(&token->value, env, last_exit_status);
}

static void process_token_list(t_token *tokens, t_env *env, int last_exit_status)
{
    t_token *current;

    current = tokens;
    while (current && current->type != TOKEN_EOF)
    {
        expand_single_token(current, env, last_exit_status);
        current = current->next;
    }
}

static void handle_word_splitting(t_token **tokens)
{
    split_expanded_tokens(tokens);
}

static void cleanup_empty_tokens(t_token **tokens)
{
    remove_empty_tokens(tokens);
}

void expand_tokens(t_token *tokens, t_env *env, int last_exit_status)
{
    if (!tokens || !env)
        return;
    process_token_list(tokens, env, last_exit_status);
    handle_word_splitting(&tokens);
    cleanup_empty_tokens(&tokens);
}
