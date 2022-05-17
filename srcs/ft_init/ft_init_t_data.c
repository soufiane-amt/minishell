/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_t_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelmoham <eelmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 23:51:58 by samajat           #+#    #+#             */
/*   Updated: 2022/05/17 22:04:22 by eelmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    ft_init_t_data ()
{
    data.status.exit_code = 0;
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