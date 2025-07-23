/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mah-ming <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 19:20:36 by mah-ming          #+#    #+#             */
/*   Updated: 2025/07/20 17:58:26 by mah-ming         ###   ########.fr       */
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
	char 			*value; // valeur, echo, >>, ...
	t_token_type 	type; // type du token
	int 			space_after; // gerer les cas echo test1"test2" : test1test2
	struct s_token 	*next; // token suivant
	struct s_token	*prev; // token prescedent, utile pour les redir apres un pipe
}			t_token;

typedef enum e_quote_state
{
    QUOTE_NONE,
    QUOTE_SINGLE,
    QUOTE_DOUBLE
}   t_quote_state;

typedef struct s_redir
{
    t_token_type    type;       // type de redir
    char            *file;      // file
    char            *delimiter; // heredoc
    struct s_redir  *next;
}   t_redir;

typedef struct s_cmd
{
    char            **args;     // args
    int             arg_count;  // nbr d'arg
    t_redir         *redirs;    // liste des redir
    struct s_cmd    *next;      // pipe
}   t_cmd;
