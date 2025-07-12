/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mah-ming <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 13:12:58 by mah-ming          #+#    #+#             */
/*   Updated: 2025/07/12 13:21:12 by mah-ming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int contains_whitespace(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (is_whitespace(str[i]))
            return (1);
        i++;
    }
    return (0);
}

static int count_words(char *str)
{
    int count;
    int in_word;
    int i;

    count = 0;
    in_word = 0;
    i = 0;
    while (str[i])
    {
        if (!is_whitespace(str[i]) && !in_word)
        {
            in_word = 1;
            count++;
        }
        else if (is_whitespace(str[i]))
            in_word = 0;
        i++;
    }
    return (count);
}

char **split_by_whitespace(char *str)
{
    char **result;
    int words;
    int i;
    int j;
    int start;

    words = count_words(str);
    result = malloc(sizeof(char *) * (words + 1));
    if (!result)
        return (NULL);
    i = 0;
    j = 0;
    while (str[i] && j < words)
    {
        while (str[i] && is_whitespace(str[i]))
            i++;
        start = i;
        while (str[i] && !is_whitespace(str[i]))
            i++;
        result[j] = ft_substr(str, start, i - start);
        j++;
    }
    result[j] = NULL;
    return (result);
}

void replace_token_with_split(t_token **head, t_token *token, char **words)
{
    t_token *new_token;
    t_token *last_new;
    int i;
	(void)head;

    if (!words || !words[0])
        return;
    free(token->value);
    token->value = ft_strdup(words[0]);
    last_new = token;
    i = 1;
    while (words[i])
    {
        new_token = create_token(words[i], TOKEN_WORD);
        new_token->space_after = 1;
        new_token->prev = last_new;
        new_token->next = last_new->next;
        if (last_new->next)
            last_new->next->prev = new_token;
        last_new->next = new_token;
        last_new = new_token;
        i++;
    }
    if (last_new != token)
        last_new->space_after = token->space_after;
}

void split_expanded_tokens(t_token **head)
{
    t_token *current;
    char **words;

    if (!head || !*head)
        return;
    current = *head;
    while (current && current->type != TOKEN_EOF)
    {
        if (current->type == TOKEN_WORD && contains_whitespace(current->value))
        {
            words = split_by_whitespace(current->value);
            if (words)
            {
                replace_token_with_split(head, current, words);
                free_split(words);
            }
        }
        current = current->next;
    }
}
