/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mah-ming <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 23:57:12 by mah-ming          #+#    #+#             */
/*   Updated: 2025/07/03 21:49:43 by mah-ming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static int extract_operator(char *line, int start, char **value)
{
    if ((line[start] == '<' && line[start + 1] == '<') ||
        (line[start] == '>' && line[start + 1] == '>'))
    {
        *value = ft_substr(line, start, 2);
        return (2);
    }
    *value = ft_substr(line, start, 1);
    return (1);
}

static int process_operator(char *line, int i, t_token **head)
{
    char *value;
    t_token *token;
    int len;

    len = extract_operator(line, i, &value);
    token = create_token(value, token_id(value));
    if (!token)
    {
        free(value);
        return (-1);
    }
    token->space_after = get_space_after(line, i + len);
    add_token_list(head, token);
    free(value);
    return (len);
}

static int process_word(char *line, int i, t_token **head)
{
    int len;

    len = handle_quotes_in_word(line, i, head);
    if (len == -1)
        return (-1);
    return (len);
}

static int tokenize_loop(char *line, t_token **head)
{
    int i;
    int len;

    i = 0;
    while (line[i])
    {
        skip_whitespace(line, &i);
        if (!line[i])
            break;
        if (is_operator_char(line[i]))
            len = process_operator(line, i, head);
        else
            len = process_word(line, i, head);
        if (len == -1)
            return (-1);
        i += len;
    }
    return (0);
}

t_token *tokenize(char *line)
{
    t_token *head;
    t_token *eof_token;

    head = NULL;
    if (!line)
        return (NULL);
    if (tokenize_loop(line, &head) == -1)
    {
        free_token_list(head);
        return (NULL);
    }
    eof_token = create_token("", TOKEN_EOF);
    if (eof_token)
        add_token_list(&head, eof_token);
    return (head);
}
