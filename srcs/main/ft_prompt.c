/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelmoham <eelmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 23:00:44 by samajat           #+#    #+#             */
/*   Updated: 2022/05/26 19:38:27 by eelmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parse_and_execute(void)
{
	t_token	**token;

	if (g_data.input_piped)
	{
		token = init_token();
		ft_get_token(token);
		exec_cmd_ln (token);
		free_tokens(token);
	}
	else if (!*(g_data.status.exit_code))
		exec_cmd_ln (NULL);
	add_history(g_data.input);
}

void	open_prompt(char **env)
{
	g_data.is_running = 0;
	signalize();
	get_env_while_prompt('=', env);
	g_data.exit_the_program = 0;
	while (!g_data.exit_the_program)
	{
		g_data.input = readline("𝖒𝖎𝖓𝖎𝖘𝖍𝖊𝖑𝖑➜");
		if (!g_data.input)
		{
			printf("exit\n");
			break ;
		}
		ft_collect_data();
		if (!(*g_data.status.exit_code) && check_user_input(g_data.input))
			parse_and_execute();
		if ((*g_data.status.exit_code))
			notify_error(g_data.status.status, NULL);
		free_t_data();
		g_data.error_status = *(g_data.status.exit_code);
	}
	free_enver();
}
