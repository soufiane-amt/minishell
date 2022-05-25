/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_t_g_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 23:51:58 by samajat           #+#    #+#             */
/*   Updated: 2022/05/24 19:43:38 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_init_t_data(void)
{
	g_data.status.status = NULL;
	g_data.status.exit_code = malloc (sizeof(int));
	if (!g_data.status.exit_code)
	{
		if (g_data.input)
			free (g_data.input);
		exit(30);
	}
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
	g_data.mypath = NULL;
	g_data.fds = NULL;
	g_data.spliter_sucess = 1;
}
