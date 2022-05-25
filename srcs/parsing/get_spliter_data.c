/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_spliter_g_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 14:50:44 by samajat           #+#    #+#             */
/*   Updated: 2022/05/24 19:59:13 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_is_sep(t_spliter *spliter, char c)
{
	if (c == PIPE && !g_data.status.status)
	{
		pipe(spliter->pipe);
		g_data.process_nbr++;
		return (1);
	}
	return (0);
}

char	**get_two_separated_cmd(char *str, char sep)
{
	char	**two_cmd;

	if (!str)
		chstatus(MEMORY_LACK, NULL, 30);
	if ((*g_data.status.exit_code))
		return (NULL);
	two_cmd = ft_split (str, sep);
	if (!two_cmd)
	{
		chstatus(MEMORY_LACK, NULL, 30);
		free(str);
		return (NULL);
	}
	free (str);
	return (two_cmd);
}

int	get_spliter_data(t_spliter *spliter, char *prev_cmd, char *next_cmd)
{
	static t_cmd	*prevcommand;

	if (!g_data.call_nbr)
		spliter->prev_cmd = get_cmd_data(prev_cmd);
	else
		spliter->prev_cmd = prevcommand;
	spliter->next_cmd = get_cmd_data(next_cmd);
	prevcommand = spliter -> next_cmd;
	if (spliter ->spec_char == PIPE && !g_data.status.status)
	{
		spliter ->prev_cmd->output.fd = spliter->pipe[1];
		spliter ->next_cmd->input.fd = spliter->pipe[0];
		open_redir_files(spliter->prev_cmd);
		open_redir_files(spliter->next_cmd);
		ft_lstadd_back(&g_data.fds, ft_lstnew(&spliter->pipe[1], INT));
		ft_lstadd_back(&g_data.fds, ft_lstnew(&spliter->pipe[0], INT));
	}
	else
	{
		return (0);
	}
	g_data.call_nbr++;
	return (1);
}

t_spliter	*get_spliter(t_spliter *spliter)
{
	char	**cmd;

	g_data.l = g_data.i + 1;
	spliter->spec_char = g_data.input[g_data.i];
	while (g_data.input[g_data.l] && g_data.input[g_data.l] != '\n'
		&& g_data.input[g_data.l] != spliter->spec_char)
		g_data.l++;
	cmd = get_two_separated_cmd(
			ft_substr(g_data.input, g_data.j, g_data.l + 1), spliter->spec_char);
	if (!cmd || (*g_data.status.exit_code)
		|| !get_spliter_data(spliter, cmd[0], cmd[1]))
	{
		free_arr((void **)cmd);
		g_data.spliter_sucess = 0;
		return (spliter);
	}
	free_arr((void **)cmd);
	(g_data.i)++;
	g_data.j = g_data.i;
	return (spliter);
}

t_spliter	*ft_split_by_sep(void)
{
	t_spliter	*spliter;

	spliter = malloc (sizeof(t_spliter));
	if (!spliter)
	{
		chstatus(MEMORY_LACK, NULL, 30);
		return (NULL);
	}
	spliter->prev_cmd = NULL;
	spliter->next_cmd = NULL;
	while (g_data.input[g_data.i])
	{
		if (ft_is_sep(spliter, g_data.input[g_data.i]))
			return (get_spliter(spliter));
		(g_data.i)++;
	}
	free(spliter);
	return (NULL);
}
