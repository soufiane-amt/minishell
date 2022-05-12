/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_content.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 21:25:34 by samajat           #+#    #+#             */
/*   Updated: 2022/04/20 01:55:57 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void display_file(int    fd)
{
    char    *str;

    str = ft_strdup("");
    while (str )
    {
        // printf ("--\n");
        fprintf(stderr, "%s\n", str);
        get_next_line(fd);
    }
    close(fd);
}