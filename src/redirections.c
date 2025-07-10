/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbosviel <marvin@d42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 14:05:36 by tbosviel          #+#    #+#             */
/*   Updated: 2025/07/02 14:05:36 by tbosviel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	redir_out(char *filename)
{
	int	fd;

	fd = 0;
	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	dup2(fd, STDOUT_FILENO);
	close(fd);
}

void	redir_out_append(char *filename)
{
	int	fd;

	fd = 0;
	fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0644);
	dup2(fd, STDOUT_FILENO);
	close(fd);
}

void	redir_in(char *filename)
{
	int	fd;

	fd = 0;
	fd = open(filename, O_RDONLY, 0444);
	dup2(fd, STDIN_FILENO);
	close(fd);
}

// void	heredoc(char *delemiter)
// {
	// char	*line;
//
	// line = NULL;
	// while (1)
	// {
		// write(1, "heredoc> ", 9);
		// if (ft_strncmp() == 0)
			// break ;
	// }
// }
