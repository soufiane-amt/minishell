/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 22:08:51 by eelmoham          #+#    #+#             */
/*   Updated: 2022/05/15 23:13:14 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    ft_env(t_cmd *cmd ,int is)
{
    t_env *e;

    e = data.enver;
    (void)cmd;
    printf("****\n");
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
        if (is == 0)
            printf("declare -x %s=%s\n", e->variable, e->value);
        e = e->next;
    }
    // printf("%s   %s\n", ft_env_last(data.enver)->variable, ft_env_last(data.enver)->value);
    // printf("****\n");
}