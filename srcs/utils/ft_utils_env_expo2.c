/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_env_expo2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelmoham <eelmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 22:33:05 by eelmoham          #+#    #+#             */
/*   Updated: 2022/03/31 22:35:41 by eelmoham         ###   ########.fr       */
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