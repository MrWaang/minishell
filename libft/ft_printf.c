/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbosviel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 10:52:38 by tbosviel          #+#    #+#             */
/*   Updated: 2024/11/03 03:47:06 by tbosviel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_strchr(const char *str, int searched)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (char)searched)
			return ((char *)&str[i]);
		i++;
	}
	if (str[i] == (char)searched)
		return ((char *)&str[i]);
	return (0);
}

int	format_type(int count, char c, va_list args)
{
	if (c == 'c')
		count += ft_printf_c(va_arg(args, int));
	else if (c == 's')
		count += ft_printf_s(va_arg(args, char *));
	else if (c == 'p')
		count += ft_printf_p(va_arg(args, void *));
	else if (c == 'd')
		count += ft_printf_d(va_arg(args, int));
	else if (c == 'i')
		count += ft_printf_i(va_arg(args, int));
	else if (c == 'u')
		count += ft_printf_u(va_arg(args, unsigned int));
	else if (c == 'x')
		count += ft_printf_x(va_arg(args, size_t));
	else if (c == 'X')
		count += ft_printf_upper_x(va_arg(args, size_t));
	else
		count += ft_printf_c('%');
	return (count);
}

int	if_ft_printf(int count, int i, const char *format, va_list args)
{
	if (format[i + 1] == ' ' || format[i + 1] == '\0')
		return (-1);
	else if (ft_strchr("csdxXipu%", format[i + 1]))
		count = format_type(count, format[i + 1], args);
	else
		count += write(1, format + i, 2);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	count = 0;
	i = 0;
	if (format == NULL)
		return (-1);
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			count = if_ft_printf(count, i, format, args);
			if (count == -1)
				return (count);
			i++;
		}
		else
			count += write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}
