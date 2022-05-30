/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelmoham <eelmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 12:15:27 by eelmoham          #+#    #+#             */
/*   Updated: 2022/05/30 18:20:44 by eelmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	configure_terminal(struct termios *config)
{
	if (tcgetattr(0, config) < 0)
		return ;
	config->c_lflag &= ~(ECHO | ICANON);
	if (tcsetattr(0, 0, config) < 0)
		return ;
}

void	unconfigure_terminal(struct termios *config)
{
	config->c_lflag |= (ECHO | ICANON);
	if (tcsetattr(0, 0, config) < 0)
		return ;
}

void	ctl(int sig)
{
	struct termios	config;

	(void)sig;
	if (g_data.is_running)
	{
		g_data.is_running = 0;
		return ;
	}
	if(!g_data.exit_herdoc)
	{
		configure_terminal(&config);
		rl_replace_line("", 0);
		ioctl(0, TIOCSTI, "\n");
		unconfigure_terminal(&config);
		g_data.exit_herdoc = TRUE;
	}
	else
	{
		configure_terminal(&config);
		rl_replace_line("", 0);
		ioctl(0, TIOCSTI, "\n");
		unconfigure_terminal(&config);
	}
}

// void	ctl(int sig)
// {
// 	if (sig == SIGINT)
// 	{
// 		printf("\r");
// 		rl_on_new_line();
// 		rl_redisplay();
// 		printf("\n");
// 		rl_on_new_line();
// 		rl_replace_line("", 0);
// 		rl_redisplay();
// 		(*g_data.status.exit_code) = 128 + sig;
// 	}
// }

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
