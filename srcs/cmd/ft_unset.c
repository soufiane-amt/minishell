/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelmoham <eelmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 15:03:57 by samajat           #+#    #+#             */
/*   Updated: 2022/05/10 19:54:33 by eelmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    ft_unset(t_data *data, t_cmd *cmd)
{
    t_env *e;
    t_list *arg;
    char *var;

    arg = cmd->args;
    if (ft_lstsize(cmd->options) > 0)
    {
        perror("builtin command\n");
        // set variable error = 1 here
        return ;
    }
    while (arg)
    {
        e = data->enver;
        while (e != NULL)
        {
            var = e->variable;
            if (!ft_strcmp(var, arg->content))
                break ;
            else if ((var[0] >= 'a' || var[0] >= 'z')
                && (var[0] >= 'A' || var[0] <= 'Z'))
                printf("unset: `%s': not a valid identifier",var);
            e = e->next;
        }
        e->value = "";
        arg = arg->next;
    }
    // set variable error = 0 here
}