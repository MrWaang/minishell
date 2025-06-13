/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mah-ming <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 18:35:09 by tbosviel          #+#    #+#             */
/*   Updated: 2025/06/12 21:37:34 by mah-ming         ###   ########.fr       */
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

// parsing
t_token 		*create_token(char *value, t_token_type type); // creations de token
void 			add_token_list(t_token **head, t_token *new_token); // lister les token
t_token_type 	token_id(char *value); // trouver a quelle token cela correspond

// fonction cas d'erreur
void 	free_array(char **array); // free un tableau
void 	free_env_list(t_env *env); // free env liste chainés
void 	free_token_list(t_token *head); // free token liste chainés

#endif
