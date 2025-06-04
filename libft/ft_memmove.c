/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbosviel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 03:11:03 by tbosviel          #+#    #+#             */
/*   Updated: 2024/10/15 01:39:03 by tbosviel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t size)
{
	size_t	i;

	if (dest == 0 && src == 0)
		return (NULL);
	if (dest > src && dest <= size + src)
	{
		i = size - 1;
		while ((int)i >= 0)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			i--;
		}
		return (dest);
	}
	i = 0;
	while (i < size)
	{
		*(unsigned char *)&dest[i] = *(unsigned char *)&src[i];
		i++;
	}
	return (dest);
}
