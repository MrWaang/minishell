/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mah-ming <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 21:10:08 by mah-ming          #+#    #+#             */
/*   Updated: 2025/06/05 22:52:49 by mah-ming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BULTINS_H
# define BULTINS_H

int 	ft_echo(char **args);
int   	ft_env(char **env);

// echo utils
int		ft_n_option(char *args); // check l'option -n de echo

// env utils
int		env_size(char **env_d); // check le nbr de var d'environnement

#endif
