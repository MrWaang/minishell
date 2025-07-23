#include "../../../includes/minishell.h"

int is_redirection(t_token_type type)
{
    if (type == TOKEN_REDIR_IN || type == TOKEN_REDIR_OUT)
        return (1);
    if (type == TOKEN_HEREDOC || type == TOKEN_D_REDIR)
        return (1);
    return (0);
}

int is_operator(t_token_type type)
{
    if (type == TOKEN_PIPE)
        return (1);
    if (is_redirection(type))
        return (1);
    return (0);
}

void skip_whitespace_tokens(t_token **token)
{
    while (*token && (*token)->type == TOKEN_WORD &&
           ft_strlen((*token)->value) == 0)
    {
        *token = (*token)->next;
    }
}

t_token *get_next_meaningful_token(t_token *token)
{
    t_token *current;

    current = token;
    while (current && current->type == TOKEN_WORD &&
           ft_strlen(current->value) == 0)
    {
        current = current->next;
    }
    return (current);
}

int is_empty_command(t_token *start, t_token *end)
{
    t_token *current;

    current = start;
    while (current && current != end)
    {
        if (current->type == TOKEN_WORD && ft_strlen(current->value) > 0)
            return (0);
        current = current->next;
    }
    return (1);
}
