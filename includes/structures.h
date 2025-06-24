/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mah-ming <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 19:20:36 by mah-ming          #+#    #+#             */
/*   Updated: 2025/06/11 18:43:04 by mah-ming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_env_node
{
	char				*line;
	struct s_env_node	*next;
}						t_env_node;

typedef struct s_env
{
	t_env_node *head; // premiere ligne
	char **c_env;     // copie de l'env qu'on recup dans le main
	int size;         // nbr de ligne
}						t_env;

typedef enum token_type
{
	TOKEN_WORD,      // arg
	TOKEN_PIPE,      // |
	TOKEN_REDIR_IN,  // <
	TOKEN_REDIR_OUT, // >
	TOKEN_HEREDOC,   // <<
	TOKEN_D_REDIR,   // >>
	TOKEN_EOF        // fin de ligne
}						t_token_type;

typedef struct s_token
{
	char *value;          // valeur, token 1, token 2, ...
	t_token_type type;    // type du token
	int space_after;      // gerer les cas echo test1"test2" : test1test2
	struct s_token *next; // token suivant
	struct s_token *prev; // token prescedent,
							// utile pour les redir apres un pipe
}						t_token;
