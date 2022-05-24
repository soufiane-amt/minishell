/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd_ln.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 00:39:59 by samajat           #+#    #+#             */
/*   Updated: 2022/05/24 19:27:23 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_one_cmd(void)
{
	t_cmd	*one_cmd;

	one_cmd = get_cmd_data (data.input);
	if ((*data.status.exit_code))
	{
		free_cmd(one_cmd);
		return ;
	}
	open_redir_files(one_cmd);
	exec_cmd(one_cmd);
	waitpid(-1, NULL, 0);
	free_cmd(one_cmd);
}

void	exec_multiple_cmd(t_token **token)
{
	int		i;
	t_token	*temp;

	i = 0;
	temp = *token;
	while (temp)
	{
		if (!(i++))
			exec_cmd(temp->sep->Prevcmd);
		exec_cmd(temp->sep->Nextcmd);
		temp = temp ->next;
	}
	while (waitpid(-1, NULL, 0) != -1)
	{
	}
}

void	exec_cmd_ln(t_token **token)
{
	(void)token;
	if ((*data.status.exit_code))
		return ;
	if (!data.input_piped)
		exec_one_cmd();
	else
		exec_multiple_cmd(token);
}
