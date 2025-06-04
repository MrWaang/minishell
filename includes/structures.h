typedef enum token_type
{
	TOKEN_WORD, // arg
	TOKEN_PIPE, // |
	TOKEN_REDIR_IN, // <
	TOKEN_REDIR_OUT, // >
	TOKEN_LEFT_SHIFT, // <<
	TOKEN_RIGHT_SHIFT, // >>
	TOKEN_EOF // fin de ligne
}			t_token_type;
