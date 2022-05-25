/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_g_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 14:18:24 by samajat           #+#    #+#             */
/*   Updated: 2022/05/25 19:24:25 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	join_back_slash(void)
{
	char	*str;
	int		i;

	i = -1;
	while (g_data.all_paths[++i])
	{
		str = g_data.all_paths[i];
		g_data.all_paths[i] = ft_strjoin (str, "/");
		if (!g_data.all_paths[i])
		{
			chstatus(MEMORY_LACK, NULL, 30);
			return ;
		}
		free(str);
	}
}

void	generate_paths(void)
{
	g_data.path = getenv("PATH");
	if (!g_data.path)
	{
		notify_error (CMD_NOT_FOUND, NULL);
		chstatus("  ", NULL, 127);
		return ;
	}
	g_data.all_paths = ft_split (g_data.path, ':');
	if (!g_data.all_paths)
	{
		chstatus(MEMORY_LACK, NULL, 30);
		return ;
	}
	join_back_slash();
}

void	ft_collect_data(char **env)
{
	int		i;
	char	*f_str;

	ft_init_t_data (env);
	f_str = g_data.input;
	g_data.input = ft_strtrim(g_data.input, " ");
	if (!g_data.input)
	{
		chstatus(MEMORY_LACK, NULL, 30);
		return ;
	}
	i = 0;
	free(f_str);
	while (g_data.input[i])
	{
		if (!cmd_piped() || !cmd_piped2())
			break;
		if (g_data.input[i] == '|')
			g_data.input_piped = TRUE;
		i++;
	}
	generate_paths();
	if ((*g_data.status.exit_code))
		return ;
}
