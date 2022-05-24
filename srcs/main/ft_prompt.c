/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 23:00:44 by samajat           #+#    #+#             */
/*   Updated: 2022/05/24 21:20:25 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parse_and_execute(void)
{
	t_token	**token;

	if (data.input_piped)
	{
		token = init_token();
		ft_get_token(token);
		exec_cmd_ln (token);
		free_tokens(token);
	}
	else if (!*(data.status.exit_code))
		exec_cmd_ln (NULL);
	add_history(data.input);
}

void	open_prompt(char **env)
{
	signalize();
	get_env_while_prompt('=', env);
	data.exit_the_program = 0;
	while (!data.exit_the_program)
	{
		data.input = readline("𝖒𝖎𝖓𝖎𝖘𝖍𝖊𝖑𝖑➜");
		if (!data.input)
			break ;
		ft_collect_data();
		if (!(*data.status.exit_code) && check_user_input(data.input))
			parse_and_execute();
		if ((*data.status.exit_code))
			notify_error(data.status.status, NULL);
		free_t_data();
		data.error_status = *(data.status.exit_code);
	}
	free_enver();
}
