/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mah-ming <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 13:08:13 by mah-ming          #+#    #+#             */
/*   Updated: 2025/07/12 13:18:34 by mah-ming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int is_single_quoted(char *str)
{
    int len;

    if (!str || !*str)
        return (0);
    len = ft_strlen(str);
    if (len >= 2 && str[0] == '\'' && str[len - 1] == '\'')
        return (1);
    return (0);
}

int is_double_quoted(char *str)
{
    int len;

    if (!str || !*str)
        return (0);
    len = ft_strlen(str);
    if (len >= 2 && str[0] == '"' && str[len - 1] == '"')
        return (1);
    return (0);
}

char *extract_quoted_content(char *str)
{
    int len;
    char *content;

    if (!str || !*str)
        return (ft_strdup(""));
    len = ft_strlen(str);
    if (len < 2)
        return (ft_strdup(str));
    content = ft_substr(str, 1, len - 2);
    return (content);
}

void remove_quotes(char **str)
{
    char *new_str;

    if (!str || !*str)
        return;
    if (!is_single_quoted(*str) && !is_double_quoted(*str))
        return;
    new_str = extract_quoted_content(*str);
    if (new_str)
    {
        free(*str);
        *str = new_str;
    }
}

void process_quotes_in_token(t_token *token)
{
    if (!token || !token->value)
        return;
    remove_quotes(&token->value);
}
