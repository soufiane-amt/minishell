/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 12:15:27 by eelmoham          #+#    #+#             */
/*   Updated: 2022/05/25 20:03:42 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void  ctl(int sig)
{
	if (sig == SIGINT)
	{
		printf("\r");
		rl_on_new_line();
		rl_redisplay();
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		(*g_data.status.exit_code) = 128 + sig;
	}
	if (sig == SIGQUIT)
		return ;
	(*g_data.status.exit_code) = 0;
}

void	signalize(void)
{
	signal(SIGINT, ctl);
	signal(SIGQUIT, ctl);
}
