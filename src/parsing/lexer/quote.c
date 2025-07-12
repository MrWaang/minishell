/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mah-ming <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 21:23:11 by mah-ming          #+#    #+#             */
/*   Updated: 2025/07/03 21:49:41 by mah-ming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static int find_closing_quote(char *line, int start, char quote_char)
{
    int i;

    i = start + 1;
    while (line[i] && line[i] != quote_char)
        i++;
    if (!line[i])
        return (-1);
    return (i);
}

static int add_word_token(char *line, int start, int len, t_token **head)
{
    char *value;
    t_token *token;

    if (len <= 0)
        return (0);
    value = ft_substr(line, start, len);
    token = create_token(value, TOKEN_WORD);
    free(value);
    if (!token)
        return (-1);
    token->space_after = 0;
    add_token_list(head, token);
    return (0);
}

static int process_quoted_section(char *line, int *i, t_token **head)
{
    char quote_char;
    int close_pos;

    quote_char = line[*i];
    close_pos = find_closing_quote(line, *i, quote_char);
    if (close_pos == -1)
    {
        write(2, "minishell: syntax error: unclosed quote\n", 41);
        return (-1);
    }
    if (add_word_token(line, *i, close_pos - *i + 1, head) == -1)
        return (-1);
    *i = close_pos + 1;
    return (0);
}

static int process_unquoted_section(char *line, int *i, int word_start, t_token **head)
{
    if (*i > word_start)
    {
        if (add_word_token(line, word_start, *i - word_start, head) == -1)
            return (-1);
    }
    return (0);
}

int handle_quotes_in_word(char *line, int start, t_token **head)
{
    int i;
    int word_start;
    t_token *last;

    i = start;
    word_start = i;
    while (line[i] && !is_special_char(line[i]))
    {
        if (is_quote(line[i]))
        {
            if (process_unquoted_section(line, &i, word_start, head) == -1)
                return (-1);
            if (process_quoted_section(line, &i, head) == -1)
                return (-1);
            word_start = i;
        }
        else
            i++;
    }
    if (process_unquoted_section(line, &i, word_start, head) == -1)
        return (-1);
    last = find_last_token(*head);
    if (last)
        last->space_after = get_space_after(line, i);
    return (i - start);
}
