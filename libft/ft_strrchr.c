/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbosviel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 01:01:14 by tbosviel          #+#    #+#             */
/*   Updated: 2024/10/15 01:20:12 by tbosviel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str);

char	*ft_strrchr(const char *str, int searched)
{
	int	i;

	i = ft_strlen((const char *)str);
	while (i >= 0)
	{
		if (str[i] == (char)searched)
			return ((char *)&str[i]);
		i--;
	}
	return (0);
}
