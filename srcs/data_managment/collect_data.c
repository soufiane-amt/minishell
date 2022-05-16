/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 14:18:24 by samajat           #+#    #+#             */
/*   Updated: 2022/05/16 21:18:26 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    join_back_slash()
{
    char    *str;
    int     i;

	i = -1;
    while (data.all_paths[++i])
	{
		str = data.all_paths[i];
		data.all_paths[i] = ft_strjoin (str, "/");
        if (!data.all_paths[i])
        {
            chstatus(MEMORY_LACK, NULL, 30);
            return ;
        }
		free(str);
	}
}
void	generate_paths()
{
	data.path = getenv("PATH");
	if (!data.path)
    {
        notify_error (CMD_NOT_FOUND, NULL);
        chstatus("  ", NULL, 127);
		return ;
    }
	data.all_paths = ft_split (data.path, ':');
    if (!data.all_paths)
    {
        chstatus(MEMORY_LACK, NULL, 30);
        return ;
    }
    join_back_slash();
}

void    ft_collect_data(char  **env)
{
    int     i;
    char    *f_str;

    ft_init_t_data (env);
    f_str = data.input;
    data.input = ft_strtrim(data.input, " ");
    if (!data.input)
    {
        chstatus(MEMORY_LACK, NULL, 30);
        return ;
    }
    i = 0;
    free(f_str);
    while (data.input[i])
    {
        if (data.input[i] == '|')
            data.input_piped = TRUE;
        i++;
    }
    generate_paths();
    if (*data.status.exit_code)
        return ;
}
