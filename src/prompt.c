/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mah-ming <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 12:22:11 by tbosviel          #+#    #+#             */
/*   Updated: 2025/07/20 18:03:53 by mah-ming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// void print_history(void)
// {
//     HIST_ENTRY  **h;
//     int         i;

//     i = 0;
//     h = history_list();
//     if (!h)
//     {
//         printf("no history\n");
//         return ;
//     }
//     while (h[i])
//     {
//         printf("%d: %s\n", i + history_base, h[i]->line);
//         i++;
//     }
// }

void prompt(void)
{
    char    *input;
    t_token *tokens;
    t_cmd   *commands;

    setup_signals();

    while (1)
    {
        input = readline("minishell$ ");
        if (!input)
        {
            write(1, "exit\n", 5);
            break;
        }
        if (*input)
            add_history(input);
        tokens = tokenize(input);
        if (tokens)
        {
            expand_tokens(tokens, g_env, g_last_exit_status);
            if (check_syntax(tokens) == 0)
            {
                commands = parse_tokens(tokens);
                if (commands)
                {
                    execute_commands(commands, g_env);
                    free_cmd_list(commands);
                }
            }
            free_token_list(tokens);
        }
        free(input);
    }
}
