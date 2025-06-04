/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbosviel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 00:33:02 by tbosviel          #+#    #+#             */
/*   Updated: 2024/10/15 01:20:26 by tbosviel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *str, int searched)
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
