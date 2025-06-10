/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mah-ming <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 21:10:08 by mah-ming          #+#    #+#             */
/*   Updated: 2025/06/05 18:54:20 by mah-ming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

int		ft_echo(char **args);
void	ft_env(char **env);
int		ft_unset(char **env, char **args);
int		ft_cd(char **env, char *path);
int		ft_export(char **env, char **args);

// built-in utils
int		ft_n_option(char *args);
int		first_occurrence(char *str, char c);

#endif
