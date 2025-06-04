/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbosviel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 11:15:19 by tbosviel          #+#    #+#             */
/*   Updated: 2024/11/01 02:16:47 by tbosviel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_printf_c(char c);
int	ft_printf_s(char *str);
int	ft_printf_d(int d);
int	ft_printf_x(unsigned int nb);
int	ft_printf_upper_x(unsigned int nb);
int	ft_printf_i(int d);
int	ft_printf_u(unsigned int d);
int	ft_printf_p(void *adress);
#endif
