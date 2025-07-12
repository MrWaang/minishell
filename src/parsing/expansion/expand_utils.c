/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mah-ming <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 13:09:26 by mah-ming          #+#    #+#             */
/*   Updated: 2025/07/12 13:56:08 by mah-ming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int should_expand_token(t_token *token)
{
    if (!token)
        return (0);
    if (token->type != TOKEN_WORD)
        return (0);
    return (1);
}

int is_expandable_char(char c)
{
    if (c >= 'A' && c <= 'Z')
        return (1);
    if (c >= 'a' && c <= 'z')
        return (1);
    if (c >= '0' && c <= '9')
        return (1);
    if (c == '_')
        return (1);
    return (0);
}

void remove_empty_tokens(t_token **head)
{
    t_token *current;
    t_token *to_remove;

    if (!head || !*head)
        return;
    current = *head;
    while (current && current->type != TOKEN_EOF)
    {
        if (current->type == TOKEN_WORD && ft_strlen(current->value) == 0)
        {
            to_remove = current;
            if (current->prev)
                current->prev->next = current->next;
            else
                *head = current->next;
            if (current->next)
                current->next->prev = current->prev;
            current = current->next;
            free(to_remove->value);
            free(to_remove);
        }
        else
            current = current->next;
    }
}

int count_varname_len(char *str)
{
    int i;

    i = 0;
    if (str[0] == '?')
        return (1);
    while (str[i] && is_expandable_char(str[i]))
        i++;
    return (i);
}
