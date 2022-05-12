/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_word_after.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 16:24:46 by samajat           #+#    #+#             */
/*   Updated: 2022/04/02 20:34:20 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_isspace (char c)
{
    if (c =='\t' || c =='\n' || c == '\v' ||
        c == '\f' || c == '\r' || c == ' ')
        return (1);
    return (0);
}

char    *ft_get_word_after_c(char  *str, char c)
{
    int i;
    char    *returned;
    int start;
    int length;

    i = 0;
    length = 0;
    
    while (str[i] && ft_isspace (str[i]))
        i++;
    while (str[i] && str[i] != c)
        i++;
    i++;
    //handle the >> case here
    start = i;
    while (str[i] && str[i] != c)
    {
        length++;
        i++;
    }
    returned = ft_substr(str + start, 0,(size_t)length);
    return (returned);
}
