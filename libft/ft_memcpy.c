/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbosviel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 21:57:44 by tbosviel          #+#    #+#             */
/*   Updated: 2024/10/15 01:36:21 by tbosviel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t size)
{
	int				i;
	unsigned char	*dst;
	unsigned char	*source;

	i = size;
	dst = (unsigned char *)dest;
	source = (unsigned char *)src;
	if (dst == 0 && source == 0)
		return (NULL);
	while (size > 0)
	{
		dst[i - size] = source[i - size];
		size--;
	}
	return (dst);
}
