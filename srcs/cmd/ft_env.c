/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelmoham <eelmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 22:08:51 by eelmoham          #+#    #+#             */
/*   Updated: 2022/05/16 13:06:36 by eelmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    ft_env(int is)
{
    t_env *e;

    e = data.enver;
    while (e)
    {
        if (is == 1 && ft_strcmp(e->value, ""))
            printf("%s=%s\n", e->variable, e->value);
        if (is == 0)
            printf("declare -x %s=%s\n", e->variable, e->value);
        e = e->next;
    }
    // printf("%s   %s\n", ft_env_last(data.enver)->variable, ft_env_last(data.enver)->value);
    // printf("****\n");
}