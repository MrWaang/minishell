/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mah-ming <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 18:35:09 by tbosviel          #+#    #+#             */
/*   Updated: 2025/06/11 19:14:26 by mah-ming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include "structures.h"
# include "builtins.h"
# include <readline/history.h>
# include <readline/readline.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

// parsing
// t_token *create_token(char *value, t_token_type type);

// fonction cas d'erreur
void	free_array(char **array);  // free un tableau
void	free_env_list(t_env *env); // free liste chainés
void	print_history(void);
void	prompt(void);
char	*find_cmd_path(char *cmd, char **env);
int		is_built_in(char *cmd);
int		built_in_headler(char *cmd, char **args, t_env *env);

#endif
