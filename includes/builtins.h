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

int		ft_echo(char **args);
int		ft_env(t_env *env);
int		ft_pwd(void);
void	ft_exit(long long int value);
int		ft_unset(char **env, char **args);
int		ft_cd(char **env, char *path);
int		ft_export(char **env, char **args);

// echo utils
int		ft_n_option(char *args); // check l'option -n de echo

// built-in utils
int		first_occurrence(char *str, char c);

// env utils
t_env_node *create_node(char *line);
void add_node_to_list(t_env *env, t_env_node *new_node);
t_env *create_env_list(char **envt);

#endif
