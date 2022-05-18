/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 23:00:44 by samajat           #+#    #+#             */
/*   Updated: 2022/05/18 23:07:51 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"

int open_prompt(char  **env)
{
    t_token  **token;
    signal(SIGINT,ctl_c);
    signal(SIGQUIT, ctl_c);
    get_env_while_prompt('=', env);
    data.status.exit_code = 0;
    while (1)
    {
        data.input = readline("𝖒𝖎𝖓𝖎𝖘𝖍𝖊𝖑𝖑➜");
        if (!data.input)
            return (0);
        ft_collect_data();
        if (!data.status.exit_code && check_user_input(data.input))
        {
            if (data.input_piped)
            {
                token = init_token();
                ft_get_token(token);
                exec_cmd_ln (token);
                free_tokens(token);
            }
            else if (!data.status.exit_code)
            {
                exec_cmd_ln (token);
            }
            add_history(data.input);
        }
        if (data.status.status)
            notify_error(data.status.status, NULL);
        free_t_data();
    }
    free_enver();
    return 0;
}