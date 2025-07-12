/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mah-ming <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 00:18:35 by mah-ming          #+#    #+#             */
/*   Updated: 2025/07/03 21:49:43 by mah-ming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int is_whitespace(char c)
{
    return (c == ' ' || c == '\t');
}

int is_operator_char(char c)
{
    return (c == '|' || c == '<' || c == '>');
}

int is_quote(char c)
{
    return (c == '\'' || c == '"');
}

void skip_whitespace(char *line, int *index)
{
    while (line[*index] && is_whitespace(line[*index]))
        (*index)++;
}

int is_special_char(char c)
{
    return (is_whitespace(c) || is_operator_char(c));
}
