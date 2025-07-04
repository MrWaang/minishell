/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mah-ming <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 21:10:08 by mah-ming          #+#    #+#             */
/*   Updated: 2025/06/11 18:43:05 by mah-ming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "minishell.h"

int			ft_echo(char **args);
int			ft_env(t_env *env);
int			ft_pwd(void);
int			ft_exit(char **args);
int			ft_unset(t_env *env, char **args);
int			ft_cd(t_env *env, char *path);
int			ft_export(t_env *env, char **args);

// echo utils
int	ft_n_option(char *args); // check l'option -n de echo

// built-in utils
int			its_env(char *env, char *arg, char c);
int			first_occurrence(char *str, char c);
char		*find_var(t_env *env, char *name);
int			ft_unset_args(t_env *env, char *arg);

// env utils
t_env_node	*create_node(char *line);
void		add_node_to_list(t_env *env, t_env_node *new_node);
t_env		*create_env_list(char **envt);

// export utils
void		ft_strccut(char *str, char c);
int			check_arg(t_env *env, char *arg);

#endif
