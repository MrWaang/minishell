#include "../../../includes/minishell.h"

int should_collect_arg(t_token *token)
{
    if (!token)
        return (0);
    if (token->type != TOKEN_WORD)
        return (0);
    if (ft_strlen(token->value) == 0)
        return (0);
    return (1);
}

int process_word_token(t_cmd *cmd, t_token *token)
{
    if (!cmd || !token)
        return (-1);
    add_argument(cmd, token->value);
    return (0);
}

void advance_token(t_token **tokens)
{
    if (!tokens || !*tokens)
        return;
    *tokens = (*tokens)->next;
}

int is_delimiter(t_token *token)
{
    if (!token)
        return (1);
    if (token->type == TOKEN_PIPE || token->type == TOKEN_EOF)
        return (1);
    return (0);
}

int collect_arguments(t_cmd *cmd, t_token **tokens)
{
    while (*tokens && !is_delimiter(*tokens))
    {
        if (is_redir_token((*tokens)->type))
        {
            if (parse_redirection(cmd, tokens) == -1)
                return (-1);
        }
        else if (should_collect_arg(*tokens))
        {
            if (process_word_token(cmd, *tokens) == -1)
                return (-1);
            advance_token(tokens);
        }
        else
            advance_token(tokens);
    }
    return (0);
}
