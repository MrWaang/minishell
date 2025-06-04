/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbosviel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 02:51:52 by tbosviel          #+#    #+#             */
/*   Updated: 2025/02/25 00:47:51 by tbosviel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_substr(char const *s, unsigned int start, size_t len);

static size_t	count_words(char const *s, char c)
{
	size_t	i;
	size_t	count;

	count = 0;
	i = 0;
	if (s[i] != c && s[i])
		count++;
	while (s[i])
	{
		if (s[i] == c)
		{
			while (s[i] == c)
			{
				if (s[i + 1] != c && s[i + 1])
					count++;
				i++;
			}
		}
		i++;
	}
	return (count);
}

static char	**ft_freeall(size_t word, char **strs)
{
	if (!strs)
		return (NULL);
	while (word > 0)
	{
		word--;
		free(strs[word]);
	}
	free(strs);
	return (NULL);
}

static char	**strcut(size_t word, char const *s, char **strs, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < ft_strlen(s) && word < count_words(s, c))
	{
		if (s[i] && s[i] != c)
		{
			j = i;
			while (s[j] && s[j] != c)
				j++;
			strs[word] = ft_substr(s, i, j - i);
			if (strs[word] == NULL)
				return (ft_freeall(word, strs));
			i = j;
			while (i + 1 < ft_strlen(s) && s[i + 1] == c)
				i++;
			word++;
		}
		i++;
	}
	strs[word] = NULL;
	return (strs);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;

	if (s == NULL)
		return (NULL);
	strs = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (strs == NULL)
		return (NULL);
	return (strcut(0, s, strs, c));
}
