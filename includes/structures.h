/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mah-ming <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 19:20:36 by mah-ming          #+#    #+#             */
/*   Updated: 2025/06/05 18:54:17 by mah-ming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef enum token_type
{
	TOKEN_WORD, // arg
	TOKEN_PIPE, // |
	TOKEN_REDIR_IN, // <
	TOKEN_REDIR_OUT, // >
	TOKEN_HEREDOC, // <<
	TOKEN_D_REDIR, // >>
	TOKEN_EOF // fin de ligne
}			t_token_type;

typedef struct s_env
{
	char **c_env; // copie de l'env qu'on recup dans le main
}			t_env;
