#include "../../../includes/minishell.h"

t_redir *create_redir(t_token_type type, char *file)
{
    t_redir *redir;

    redir = malloc(sizeof(t_redir));
    if (!redir)
        return (NULL);
    redir->type = type;
    redir->file = ft_strdup(file);
    redir->delimiter = NULL;
    if (type == TOKEN_HEREDOC)
        redir->delimiter = ft_strdup(file);
    redir->next = NULL;
    return (redir);
}

void add_redir_to_cmd(t_cmd *cmd, t_redir *redir)
{
    t_redir *current;

    if (!cmd || !redir)
        return;
    if (!cmd->redirs)
    {
        cmd->redirs = redir;
        return;
    }
    current = cmd->redirs;
    while (current->next)
        current = current->next;
    current->next = redir;
}

int parse_redirection(t_cmd *cmd, t_token **current)
{
    t_token_type redir_type;
    t_redir *redir;

    if (!current || !*current || !cmd)
        return (-1);
    redir_type = (*current)->type;
    *current = (*current)->next;
    if (!*current || (*current)->type != TOKEN_WORD)
        return (-1);
    redir = create_redir(redir_type, (*current)->value);
    if (!redir)
        return (-1);
    add_redir_to_cmd(cmd, redir);
    *current = (*current)->next;
    return (0);
}

void free_redir_list(t_redir *redirs)
{
    t_redir *next;

    while (redirs)
    {
        next = redirs->next;
        if (redirs->file)
            free(redirs->file);
        if (redirs->delimiter)
            free(redirs->delimiter);
        free(redirs);
        redirs = next;
    }
}

int is_redir_token(t_token_type type)
{
    if (type == TOKEN_REDIR_IN || type == TOKEN_REDIR_OUT)
        return (1);
    if (type == TOKEN_HEREDOC || type == TOKEN_D_REDIR)
        return (1);
    return (0);
}
