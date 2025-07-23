/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mah-ming <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 19:44:56 by mah-ming          #+#    #+#             */
/*   Updated: 2025/07/13 19:44:57 by mah-ming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void print_syntax_error(char *token)
{
    write(2, "minishell: syntax error near unexpected token `", 47);
    write(2, token, ft_strlen(token));
    write(2, "'\n", 2);
}

void print_unexpected_token_error(char *token)
{
    write(2, "minishell: syntax error: unexpected token `", 43);
    write(2, token, ft_strlen(token));
    write(2, "'\n", 2);
}

void print_unexpected_newline_error(void)
{
    write(2, "minishell: syntax error near unexpected token `newline'\n", 56);
}

void print_unclosed_quote_error(void)
{
    write(2, "minishell: syntax error: unclosed quote\n", 41);
}

int set_syntax_error(char *near_token)
{
    if (ft_strcmp(near_token, "newline") == 0)
        print_unexpected_newline_error();
    else
        print_syntax_error(near_token);
    return (1);
}
