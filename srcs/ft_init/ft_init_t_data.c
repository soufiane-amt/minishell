/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_t_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelmoham <eelmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 23:51:58 by samajat           #+#    #+#             */
/*   Updated: 2022/05/30 21:40:23 by eelmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_init_t_data(void)
{
	g_data.status.status = NULL;
	*(g_data.status.exit_code) = 0;
	g_data.input_piped = FALSE;
	g_data.i = 0;
	g_data.j = 0;
	g_data.l = 0;
	g_data.e = 0;
	g_data.c = 0;
	g_data.call_nbr = 0;
	g_data.process_nbr = 1;
	g_data.all_paths = NULL;
	g_data.mypath =  NULL;
	g_data.fds = NULL;
	g_data.spliter_sucess = 1;
	g_data.command_executing = FALSE;
}
