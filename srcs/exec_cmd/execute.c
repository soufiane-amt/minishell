/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 21:13:23 by samajat           #+#    #+#             */
/*   Updated: 2022/05/25 22:39:41 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	close_fd(t_cmd *cmd, int close_all)
{
	t_list	*temp;

	if (!close_all)
	{
		if (cmd->input.fd != STDIN_FILENO)
			close (cmd->input.fd);
		if (cmd->output.fd != STDOUT_FILENO)
			close (cmd->output.fd);
	}
	else
	{
		temp = g_data.fds;
		while (temp)
		{
			if (*((int *)temp->content) > 2)
				close(*((int *)temp->content));
			temp = temp -> next;
		}
	}
}

void	exec_cmd_in_child_process(t_cmd *cmd, int cmd_type)
{
	// (*g_data.status.exit_code) = 0;
	if (cmd->input.fd != STDIN_FILENO)
		dup2 (cmd->input.fd, STDIN_FILENO);
	if (cmd->output.fd != STDOUT_FILENO)
		dup2 (cmd->output.fd, STDOUT_FILENO);
	close_fd(cmd, 1);
	if (!cmd_type)
		execve (cmd->f_cmd[0], cmd->f_cmd, g_data.env);
	else
		exec_built_cmd(cmd, cmd_type);
	((*g_data.status.exit_code)) = 1;
	exit(1);
}

void	exec_cmd(t_cmd *cmd)
{
	int	id;
	int	cmd_type;

	cmd_type = is_built_cmd(cmd);
	id = fork();
	if (id < 0)
	{
		chstatus(OTHER_ERR, NULL, 1);
		return ;
	}
	if (id == 0 && cmd_type < 3)
	{
		g_data.is_running = 1;
		sigrestore();
		exec_cmd_in_child_process(cmd, cmd_type);
	}
	if (!id)
		exit(1);
	if (cmd_type >= 3 && !g_data.input_piped)
		exec_built_cmd(cmd, cmd_type);
	close_fd(cmd, 0);
	g_data.is_running = 0;
}
