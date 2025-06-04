/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbosviel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 03:21:55 by tbosviel          #+#    #+#             */
/*   Updated: 2024/10/15 01:07:16 by tbosviel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str);

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (dst[i] && i < size)
		i++;
	j = i;
	if (i < size)
	{
		while (src[i - j] && i < size - 1)
		{
			dst[i] = ((char *)src)[i - j];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src) + j);
}
