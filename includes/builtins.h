/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mah-ming <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 21:10:08 by mah-ming          #+#    #+#             */
/*   Updated: 2025/06/06 19:56:52 by mah-ming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

int		ft_echo(char **args);
void	ft_env(char **env);
int 	ft_pwd(void);
void    ft_exit(long long int value);
int		ft_unset(char **env, char **args);
int		ft_cd(char **env, char *path);
int		ft_export(char **env, char **args);

// echo utils
int		ft_n_option(char *args); // check l'option -n de echo

// built-in utils
int		first_occurrence(char *str, char c);

// env utils
t_env 	*init_env(char **c_env);
int		env_size(char **env_d); // check le nbr de var d'environnement
char 	**cpy_env(char **c_env); // copie de l'env
void 	free_env(t_env *env); // free l'env

#endif
