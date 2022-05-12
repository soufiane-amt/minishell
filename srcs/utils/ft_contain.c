/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_contain.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 19:11:30 by samajat           #+#    #+#             */
/*   Updated: 2022/04/11 23:02:45 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_contain_char (char c, char *to_look_for)
{
    int i;

    i = 0;
    while (to_look_for[i])
    {
        if (to_look_for[i] == c)
            return (1);
        i++;
    }
    return (0);
}

int ft_contain(char  *str, char *to_look_for)
{
    int i;

    i = 0;
    if (!str)
        return (0);
    while (str[i])
    {
        if (ft_contain_char(str[i], to_look_for))
            return (1);
        i++;
    }
    return (0);
}