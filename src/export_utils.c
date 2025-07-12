/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbosviel <marvin@d42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 13:29:22 by tbosviel          #+#    #+#             */
/*   Updated: 2025/06/23 13:29:22 by tbosviel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_strccut(char *str, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		str[i] = str[j];
		i++;
		j++;
		if (str[i] == c)
			j++;
	}
}

int	check_arg(t_env *env, char *arg)
{
	t_env_node	*tmp;
	int			i;

	i = 0;
	tmp = env->head;
	if (ft_isalpha(arg[0]) == 0 && arg[0] != '_')
		return (1);
	while (arg[i] && arg[i] != '=' && (arg[i] != '+' || arg[i + 1] != '='))
	{
		if (ft_isalnum(arg[i]) == 0 && arg[i] != '_')
			return (1);
		i++;
	}
	while (tmp)
	{
		if (ft_strncmp(tmp->line, arg, first_occurrence(tmp->line, '=')) == 0
			&& (first_occurrence(tmp->line, '=') == first_occurrence(arg, '=')
				|| (first_occurrence(tmp->line, '=') == first_occurrence(arg,
						'+'))))
			return (-1);
		tmp = tmp->next;
	}
	if (arg[first_occurrence(arg, '=') - 1] == '+')
		ft_strccut(arg, '+');
	return (0);
}
