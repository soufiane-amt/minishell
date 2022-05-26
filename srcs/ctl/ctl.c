/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelmoham <eelmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 12:15:27 by eelmoham          #+#    #+#             */
/*   Updated: 2022/05/26 19:34:34 by eelmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ctl(int sig)
{
	if (g_data.is_running)
	{
		g_data.is_running = 0;
		return ;
	}
	if (sig == SIGINT)
	{
		printf("\r");
		rl_on_new_line();
		rl_redisplay();
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		// (*g_data.status.exit_code) = 128 + sig;
	}
}

void	signalize(void)
{
	g_data.status.exit_code = malloc (sizeof(int));
	if (!g_data.status.exit_code)
	{
		if (g_data.input)
			free (g_data.input);
		exit(30);
	}
	signal(SIGINT, ctl);
	signal(SIGQUIT, SIG_IGN);
}
