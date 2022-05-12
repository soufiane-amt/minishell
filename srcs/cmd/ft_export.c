/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelmoham <eelmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 15:03:40 by samajat           #+#    #+#             */
/*   Updated: 2022/04/19 22:49:34 by eelmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
int is_exist(char *var, char *val, t_data *data)
{
    t_env *temp;

    temp = data->enver;
    while (temp)
    {
        if (!ft_strcmp(temp->variable, var))
        {
            temp->value = val;
            return (1);
        }
        temp = temp->next;
    }
    return (0);
}

void func(char *var , char *val, t_data *data)
{
    if (is_exist(var, val, data) == 0
        && ((var[0] >= 'a' || var[0] >= 'z')
        && (var[0] >= 'A' || var[0] <= 'Z')))
        ft_env_tadd_back(&(data->enver), ft_env_new(var, val));
    else
        printf("export: `%s': not a valid identifier",var);
    free(var);
    free(val); // ?? realy , I need free() here?????
}
void    ft_export(t_data *data, t_cmd *cmd)
{
    char *var;
    char *val;
    t_list *l;

    l = cmd->args;
    if (ft_lstsize(l) == 0)
        ft_env(data, 0);
    if (ft_lstsize(cmd->options) > 0)
    {
        perror("builtin command\n");
        // set variable error = 1 here
        return ;
    }
    while (l)
    {
        var = malloc(size_var_val(l->content, 1, '=') + 1);
        val = malloc(size_var_val(l->content, 0, '=') + 1);
        cpy_var_val(l->content, var, val, '=');
        func(var ,val, data);
        l = l->next;
    }
    // set variable error = 0 here
}