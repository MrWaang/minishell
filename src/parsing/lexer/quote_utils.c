/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mah-ming <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 06:42:37 by mah-ming          #+#    #+#             */
/*   Updated: 2025/07/03 21:49:41 by mah-ming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

t_quote_state get_quote_type(char c)
{
    if (c == '\'')
        return (QUOTE_SINGLE);
    if (c == '"')
        return (QUOTE_DOUBLE);
    return (QUOTE_NONE);
}

int is_quote_closed(char *line, int start, char quote_char)
{
    int i;

    i = start + 1;
    while (line[i])
    {
        if (line[i] == quote_char)
            return (1);
        i++;
    }
    return (0);
}
