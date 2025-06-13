/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mah-ming <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 18:37:25 by tbosviel          #+#    #+#             */
/*   Updated: 2025/06/12 21:43:15 by mah-ming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(int ac, char **av, char **env)
{
	t_env *c_env;

	t_token *token;
	t_token *head = NULL;
	t_token *main;
	char *types[] = {"WORD", "PIPE", "REDIR_IN", "REDIR_OUT", "HEREDOC", "D_REDIR", "EOF"};
	int i = 0;

	(void)ac;
	(void)av;

	c_env = create_env_list(env);
	ft_env(c_env);
	printf("\n\n\n\n");

	token = create_token("|", TOKEN_PIPE);
	add_token_list(&head, token);

	token = create_token("echo", TOKEN_WORD);
	add_token_list(&head, token);

	token = create_token("<<", TOKEN_HEREDOC);
	add_token_list(&head, token);

	token = create_token(">", TOKEN_REDIR_OUT);
	add_token_list(&head, token);

	main = head;
	while (main)
	{
		t_token_type type = token_id(main->value);

		printf("Token[%d]: value='%s', type=%s (id=%d)\n", i++, main->value, types[type], type);
        main = main->next;
	}
	free_token_list(head);
	return (0);
}
