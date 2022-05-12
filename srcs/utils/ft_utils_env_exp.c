/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_env_exp.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelmoham <eelmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 14:22:09 by eelmoham          #+#    #+#             */
/*   Updated: 2022/04/11 22:26:11 by eelmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void cpy_var_val(char *str, char *var, char *val, char c)
{
    int i;
    int j;
    
    i = 0;
    while (str[i] && str[i] != c)
        i++;
    j = i+ 1;
    while (str[j])
        j++;
    i = 0;
    while (str[i] && str[i] != c)
    {
        var[i] = str[i];
        i++;
    }
    var[i] = '\0';
    j = i + 1;
    i = 0;
    while (str[j])
      val[i++] = str[j++];
    val[i] = '\0';
}

int size_var_val(char *str, int x, char c)
{
    int i;
    
    i = 0;
    if (x == 1)
    {
        while (str[i] && str[i] != c)
            i++;
        return (i);
    }
    return (ft_strlen(ft_strchr(str, c)+1));
}
