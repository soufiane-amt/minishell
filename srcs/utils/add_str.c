/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 00:00:43 by samajat           #+#    #+#             */
/*   Updated: 2022/04/23 00:42:20 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    add_string(char **str, char  *added)
{
    char    *t_str;

    t_str = *str;
    *str = ft_strjoin(*str, added);
    free (t_str);
    free(added);
}