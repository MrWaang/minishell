/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbosviel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 00:00:37 by tbosviel          #+#    #+#             */
/*   Updated: 2024/10/11 18:08:29 by tbosviel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*stock;

	if (size != 0 && count > ((size_t)-1) / size)
		return (NULL);
	stock = malloc(count * size);
	if (stock == 0)
		return (NULL);
	ft_bzero(stock, count * size);
	return (stock);
}
