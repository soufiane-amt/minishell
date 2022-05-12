/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cpy_until.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 14:47:33 by samajat           #+#    #+#             */
/*   Updated: 2022/04/14 18:36:33 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


static int     is_delimter (char c, char *delimter)
{
    int i;

    i = 0;
    while (delimter[i])
    {
        if (c == delimter[i])
            return (1);
        i++;
    }
    return (0);
}

char    *ft_cpy_until(char *str, char *delimter)
{
    int i;
    char    *s;
    int     start;

    i = 0;
    if (!str || str[i] == '\n')
        return (NULL);
    while (str[i] && ft_ispace (str[i]))
        i++;
    start = i;
    while (str[i] && !is_delimter(str[i], delimter))
        i++;
    s = ft_substr(str, start, i - start);
    return (s);
}