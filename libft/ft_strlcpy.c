/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbosviel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 03:05:28 by tbosviel          #+#    #+#             */
/*   Updated: 2024/10/15 00:39:38 by tbosviel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	j = i;
	while (src[i] && i < size - 1)
	{
		dst[i] = *(char *)&src[i];
		i++;
	}
	if (i < size)
		dst[i] = '\0';
	return (ft_strlen((char *)src));
}
