#include "../../../includes/minishell.h"

int count_cmd_args(t_cmd *cmd)
{
    if (!cmd)
        return (0);
    return (cmd->arg_count);
}

int is_end_of_cmd(t_token *token)
{
    if (!token)
        return (1);
    if (token->type == TOKEN_EOF || token->type == TOKEN_PIPE)
        return (1);
    return (0);
}

t_token *skip_to_next_cmd(t_token *token)
{
    while (token && token->type != TOKEN_EOF && token->type != TOKEN_PIPE)
        token = token->next;
    if (token && token->type == TOKEN_PIPE)
        token = token->next;
    return (token);
}

char **create_args_array(int size)
{
    char **args;
    int i;

    args = malloc(sizeof(char *) * (size + 1));
    if (!args)
        return (NULL);
    i = 0;
    while (i <= size)
    {
        args[i] = NULL;
        i++;
    }
    return (args);
}
