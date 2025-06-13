/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mah-ming <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 19:59:47 by mah-ming          #+#    #+#             */
/*   Updated: 2025/06/12 21:41:25 by mah-ming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"


t_token *create_token(char *value, t_token_type type)
{
	t_token *token;

	token = malloc(sizeof(t_token));
	if (!token)
		return (NULL);
	token->value = ft_strdup(value);
	if (!token->value)
	{
		free(token);
		return (NULL);
	}
	token->type = type;
	token->space_after = 0;
	token->next = NULL;
	token->prev = NULL;
	return (token);
}

void add_token_list(t_token **head, t_token *new_token)
{
	t_token *main;

	if (!new_token)
		return;
	if (!*head)
	{
		*head = new_token;
		return;
	}
	main = *head;
	while (main->next)
		main = main->next;
	main->next = new_token;
	new_token->prev = main;
}

t_token_type token_id(char *value)
{
	if (!value || !*value)
		return (TOKEN_EOF);
	if (ft_strcmp(value, "|") == 0)
		return (TOKEN_PIPE);
	if (ft_strcmp(value, "<") == 0)
		return (TOKEN_REDIR_IN);
	if (ft_strcmp(value, ">") == 0)
		return (TOKEN_REDIR_OUT);
	if (ft_strcmp(value, "<<") == 0)
		return (TOKEN_HEREDOC);
	if (ft_strcmp(value, ">>") == 0)
		return (TOKEN_D_REDIR);
	return (TOKEN_WORD);
}

