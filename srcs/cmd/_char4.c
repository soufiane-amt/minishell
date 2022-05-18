/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _char4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 19:06:15 by eelmoham          #+#    #+#             */
/*   Updated: 2022/05/18 23:15:16 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_expand(char **_last, char *str)
{
    int i;
    int j;
    // char    *f_s;

    j = 0;
    i = 0;
    while (str[i] && *_last)
	{
		if (str[i] != -5 && str[i] != -6)
        {
			*_last = ft_charjoin(*_last, str[i]);
        }
        if (!_last)
	    {
		    chstatus(MEMORY_LACK, NULL, 55);
            free(str);
		    return (-1);
	    }
		if (str[i] == -5 || str[i] == -6)
			j++;
		i++;
	}
	(*_last)[i - j] = '\0';
    free(str);
    return (0);
}