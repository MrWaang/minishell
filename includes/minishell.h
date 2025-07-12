/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mah-ming <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 18:35:09 by tbosviel          #+#    #+#             */
/*   Updated: 2025/07/12 15:34:53 by mah-ming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
#include "structures.h"
# include "builtins.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

// lexer
t_token         *tokenize(char *line);

// token_create
t_token         *create_token(char *value, t_token_type type); // creation d'un token
void            add_token_list(t_token **head, t_token *new_token); // ajoute un token a la liste chainee
t_token_type    token_id(char *value); // definie l'id du token
int             get_space_after(char *line, int pos); // check si il y a un espace
t_token         *find_last_token(t_token *head); // trouver le dernier token de la liste chainee4

// lexer utils
int             is_whitespace(char c);
int             is_operator_char(char c);
int             is_quote(char c);
void            skip_whitespace(char *line, int *index);
int 			is_special_char(char c);

// quote
int             handle_quotes_in_word(char *line, int start, t_token **head); // process pour les quotes
t_quote_state   get_quote_type(char c); // savoir quelle type de quote
int             is_quote_closed(char *line, int start, char quote_char); // quote ferme ou non

// expand_manager.c
void    		expand_tokens(t_token *tokens, t_env *env, int last_exit_status);

// expand_quotes.c
void    		remove_quotes(char **str); // remove quote
int     		is_single_quoted(char *str); // detecte si simple quote
int     		is_double_quoted(char *str); // detecte si double quote
char    		*extract_quoted_content(char *str); // extrait le content des quotes
void    		process_quotes_in_token(t_token *token); // applique les quotes sur le token

// expand_vars.c
void    		expand_variables(char **str, t_env *env, int last_exit_status); // remplace les var
char    		*get_var_name(char *str, int start); // nom var
char    		*get_var_value(char *var_name, t_env *env, int last_exit_status); // return var value
int     		find_next_dollar(char *str, int start); // chercher $
char    		*build_expanded_str(char *str, int var_pos, char *var_name, char *value); // rebuilt la string avec la valeur de la var

// expand_utils.c
int     		should_expand_token(t_token *token); // tchecksi expand ou non
void    		remove_empty_tokens(t_token **head); // delete token
int     		is_expandable_char(char c); // tcheck si char = var ou non
int     		count_varname_len(char *str); // calcule la longeur du nom de la var

// expand_split.c
void    		split_expanded_tokens(t_token **head); // split token avec espace
int     		contains_whitespace(char *str); // tcheck espce
void    		replace_token_with_split(t_token **head, t_token *token, char **words); // decoupe ls tring
char    		**split_by_whitespace(char *str);
void    		free_split(char **split);

// fonction utils
void 			free_array(char **array); // free un tableau
void 			free_env_list(t_env *env); // free env liste chainés
void 			free_token_list(t_token *head); // free token liste chainés

#endif
