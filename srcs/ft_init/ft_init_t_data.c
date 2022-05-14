/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_t_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 23:51:58 by samajat           #+#    #+#             */
/*   Updated: 2022/05/14 19:26:22 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    ft_init_t_data ()
{
    data.status.status = NULL;
    data.status.exit_code = malloc (sizeof(int));
    if (!data.status.exit_code)
    {
        if(data.input)
            free (data.input);
        exit(30);
    }
    *(data.status.exit_code) = 0;
    data.input_piped = FALSE;
    data.i = 0;
    data.j = 0;
    data.l = 0;
    data.e = 0;
    data.c = 0;
    data.call_nbr = 0;
    data.process_nbr = 1;
    data.all_paths = NULL;
    data.mypath = NULL;
    data.fds = NULL;
    data.spliter_sucess = 1;
}