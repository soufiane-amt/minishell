/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_env_expo2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 23:02:01 by samajat           #+#    #+#             */
/*   Updated: 2022/05/12 23:02:02 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"

char *rmv_double_qt(char *str)
{
    char *var;
    int i;
    int j;

    i = 0;
    j = 0;
    var = malloc (ft_strlen(str));
    if (str[0] == '"' && str[ft_strlen(str) - 1] == '"')
    {
        while (str[i])
        {
            if (str[i] == '"')
                i++;
            else
            {
                var[j] = str[i];
                i++;
                j++;
            }
        }  
    }
    return (var);
}