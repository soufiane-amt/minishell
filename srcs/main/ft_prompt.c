/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelmoham <eelmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 15:33:59 by samajat           #+#    #+#             */
/*   Updated: 2022/05/11 18:32:08 by eelmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int open_prompt(t_data *data, char  **env)
{
    t_token  **token;

    signal(SIGINT,ctl_c);
    signal(SIGQUIT, ctl_c);
    get_env_while_prompt(data, '=');
    while (1)
    {
        data->input = readline("𝖒𝖎𝖓𝖎𝖘𝖍𝖊𝖑𝖑➜ ");
        if (!data->input)
            return (0);
        token = init_token();
        ft_collect_data(data, env);
        ft_get_token(data, token);
        // ft_tokenprint (token);
        exec_cmd_ln (data, token);
        free_tokens(*token);
        // exec_rebuilt_cmd(data);
        if (ft_strcmp(data->input, ""))
            add_history(data->input);
    }
    return 0;
}