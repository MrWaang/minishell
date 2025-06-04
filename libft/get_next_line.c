/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbosviel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 02:05:20 by tbosviel          #+#    #+#             */
/*   Updated: 2025/03/19 15:40:51 by tbosviel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

char	*free_tmp(char *buffer, char *tmp)
{
	free(tmp);
	free(buffer);
	return (NULL);
}

char	*mod_buffer(char *buffer)
{
	int		i;
	char	*tmp;
	char	*old_buffer;

	i = 0;
	old_buffer = buffer;
	if (ft_strchr(buffer, '\n'))
	{
		tmp = ft_strchr(buffer, '\n');
		buffer = ft_calloc(1, ft_strlen(tmp));
		while (tmp[i + 1])
		{
			buffer[i] = tmp[i + 1];
			i++;
		}
		free(old_buffer);
		return (buffer);
	}
	free(old_buffer);
	return (NULL);
}

char	*get_current_line(char *buffer)
{
	char	*line;
	int		i;

	line = malloc(1 * (ft_strlen(buffer) - ft_strlen(ft_strchr(buffer, '\n')))
			+ 2);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	line[i] = buffer[i];
	line[i + 1] = '\0';
	return (line);
}

char	*read_buffer(char *buffer, int fd)
{
	char	*tmp;
	int		bytes_read;
	char	*old_buffer;

	tmp = ft_calloc(1, BUFFER_SIZE + 1);
	bytes_read = 1;
	while (bytes_read > 0 && !ft_strchr(buffer, '\n'))
	{
		free(tmp);
		tmp = ft_calloc(1, BUFFER_SIZE + 1);
		bytes_read = read(fd, tmp, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free_tmp(buffer, tmp));
		old_buffer = buffer;
		buffer = ft_strjoin(buffer, tmp);
		free(old_buffer);
	}
	free(tmp);
	if (buffer[0] == '\0')
	{
		free(buffer);
		return (NULL);
	}
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (!buffer)
		buffer = ft_calloc(1, 1);
	if (fd < 0)
		return (NULL);
	buffer = read_buffer(buffer, fd);
	if (!buffer)
		return (NULL);
	line = get_current_line(buffer);
	if (!line)
		return (NULL);
	buffer = mod_buffer(buffer);
	return (line);
}
