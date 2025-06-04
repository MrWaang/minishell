/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbosviel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 00:17:54 by tbosviel          #+#    #+#             */
/*   Updated: 2024/10/18 02:02:49 by tbosviel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlen(const char *str);

static char	*ft_strcatmod(char *dst, const char *src, size_t len,
		unsigned int index)
{
	size_t	i;

	i = 0;
	while (src[i] && i < len && ft_strlen(src) > index)
	{
		dst[i] = src[index + i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (s == 0)
		return (NULL);
	if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	if (start > ft_strlen(s))
		len = 0;
	str = malloc(sizeof(char) * (len + 1));
	if (str == 0)
		return (NULL);
	return (ft_strcatmod(str, s, len, start));
}
