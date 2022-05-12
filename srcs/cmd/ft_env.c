/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelmoham <eelmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 22:08:51 by eelmoham          #+#    #+#             */
/*   Updated: 2022/05/11 18:18:34 by eelmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    ft_env(t_data *data ,int is)
{
    t_env *e;

    e = data->enver;
    // if (ft_lstsize(cmd->options) > 0)
    // {
    //     perror("builtin command\n");
    //     // set variable error = 1 here
    //     return ;
    // }
    while (e && ft_strcmp(e->value, "''"))
    {
        if (is == 1)
            printf("%s=%s\n", e->variable, e->value);
        if (is ==0)
            printf("declare -x %s=%s\n", e->variable, e->value);
        e = e->next;
    }
}