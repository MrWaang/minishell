/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_read_line.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbosviel <marvin@d42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 12:22:11 by tbosviel          #+#    #+#             */
/*   Updated: 2025/07/03 15:44:48 by tbosviel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	print_history(void)
{
	HIST_ENTRY	**h;
	int			i;

	i = 0;
	h = history_list();
	if (!h)
	{
		printf("no history\n");
		return ;
	}
	while (h[i])
	{
		printf("%d: %s\n", i + history_base, h[i]->line);
		i++;
	}
}

void	ft_readline(char *prompt, char *input)
{
	while (1)
	{
		input = readline(prompt);
		if (!input)
			break ;
		if (*input)
			add_history(input);
		free(input);
	}
}
