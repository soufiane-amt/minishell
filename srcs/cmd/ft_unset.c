/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 15:03:57 by samajat           #+#    #+#             */
/*   Updated: 2022/05/16 19:29:50 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    ft_unset(t_cmd *cmd)
{
    t_env *e;
    t_list *arg;
    char *var;

    arg = cmd->args;
    if (!arg)
        return;
    while (arg)
    {
        e = data.enver;
        while (e)
        {
            var = e->variable;
            if (!ft_strcmp(var, arg->content))
                break ;
            else if ((var[0] >= 'a' || var[0] >= 'z')
                && (var[0] >= 'A' || var[0] <= 'Z'))
                printf("unset: `%s': not a valid identifier",var);
            e = e->next;
        }
        if (e)
        {
            //Free below 
            e->value = "";
            e->variable = "";
        }
        arg = arg->next;
    }
    // set variable error = 0 here
}