/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_vars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mah-ming <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 13:08:52 by mah-ming          #+#    #+#             */
/*   Updated: 2025/07/12 13:18:35 by mah-ming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

char *get_var_name(char *str, int start)
{
    int i;
    int len;

    if (!str || str[start] != '$')
        return (NULL);
    i = start + 1;
    if (str[i] == '?')
        return (ft_strdup("?"));
    len = 0;
    while (str[i + len] && is_expandable_char(str[i + len]))
        len++;
    if (len == 0)
        return (NULL);
    return (ft_substr(str, i, len));
}

char *get_var_value(char *var_name, t_env *env, int last_exit_status)
{
    t_env_node *current;

    if (!var_name)
        return (ft_strdup(""));
    if (ft_strcmp(var_name, "?") == 0)
        return (ft_itoa(last_exit_status));
    current = env->head;
    while (current)
    {
        if (ft_strncmp(current->line, var_name, ft_strlen(var_name)) == 0
            && current->line[ft_strlen(var_name)] == '=')
            return (ft_strdup(current->line + ft_strlen(var_name) + 1));
        current = current->next;
    }
    return (ft_strdup(""));
}

int find_next_dollar(char *str, int start)
{
    int i;

    i = start;
    while (str[i])
    {
        if (str[i] == '$')
            return (i);
        i++;
    }
    return (-1);
}

char *build_expanded_str(char *str, int var_pos, char *var_name, char *value)
{
    char *before;
    char *after;
    char *temp;
    char *result;
    int var_len;

    var_len = ft_strlen(var_name) + 1;
    before = ft_substr(str, 0, var_pos);
    after = ft_strdup(str + var_pos + var_len);
    temp = ft_strjoin(before, value);
    result = ft_strjoin(temp, after);
    free(before);
    free(after);
    free(temp);
    return (result);
}

void expand_variables(char **str, t_env *env, int last_exit_status)
{
    int pos;
    char *var_name;
    char *var_value;
    char *new_str;

    if (!str || !*str || !env)
        return;
    pos = 0;
    while ((pos = find_next_dollar(*str, pos)) != -1)
    {
        var_name = get_var_name(*str, pos);
        if (!var_name)
        {
            pos++;
            continue;
        }
        var_value = get_var_value(var_name, env, last_exit_status);
        new_str = build_expanded_str(*str, pos, var_name, var_value);
        free(var_name);
        free(var_value);
        free(*str);
        *str = new_str;
        pos = 0;
    }
}
