/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mah-ming <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 18:37:25 by tbosviel          #+#    #+#             */
/*   Updated: 2025/07/12 15:34:36 by mah-ming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int main(void)
{
    t_env *env;
    t_env_node *node;
    t_token *tokens;
    t_token *current;
    char *input = "echo $USER \"$HOME\" '$PWD'";

    env = malloc(sizeof(t_env));
    env->head = NULL;
    env->size = 0;
    env->c_env = NULL;

    node = malloc(sizeof(t_env_node));
    node->line = ft_strdup("USER=maxime");
    node->next = NULL;
    env->head = node;

    node = malloc(sizeof(t_env_node));
    node->line = ft_strdup("HOME=/home/maxime");
    node->next = NULL;
    env->head->next = node;

    node = malloc(sizeof(t_env_node));
    node->line = ft_strdup("PWD=/tmp");
    node->next = NULL;
    env->head->next->next = node;
    tokens = tokenize(input);

    expand_tokens(tokens, env, 0);
    current = tokens;
    while (current && current->type != TOKEN_EOF)
    {
        printf("[%s] ", current->value);
        current = current->next;
    }
    printf("\n");

    free_token_list(tokens);
    while (env->head)
    {
        node = env->head;
        env->head = env->head->next;
        free(node->line);
        free(node);
    }
    free(env);

    return (0);
}
