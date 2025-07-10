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
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>
# include <limits.h>

// parsing
// t_token *create_token(char *value, t_token_type type);

// fonction cas d'erreur
void	free_array(char **array);  // free un tableau
void	free_env_list(t_env *env); // free liste chainés
void	print_history(void);
void	ft_readline(char *prompt, char *input);
char	*find_cmd_path(char *cmd, char **env);
int		is_built_in(char *cmd);
int		built_in_handler(char *cmd, char **args, t_env *env);
void	redir_out(char *filename);        // >
void	redir_out_append(char *filename); // >>
void	redir_in(char *filename);
void	env_array(t_env *list);
char	*is_expand(t_env *env, char *str);
void ft_exec(t_data *data, char **cmd, char **env);
void heredoc(char *delimiter);
#endif
