/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_g_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 19:07:02 by eelmoham          #+#    #+#             */
/*   Updated: 2022/05/25 19:56:49 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	get_cmd(t_cmd *cmd)
{
	cmd->cmd = ft_strdup(cmd->ex_elements->content);
	if (!cmd->cmd)
		chstatus(MEMORY_LACK, NULL, 30);
}

void	get_cmd_redirects(t_cmd *cmd)
{
	t_list	*temp;

	temp = cmd->ex_elements;
	while (temp && temp->next)
	{
		get_cmd_redirect(cmd, temp);
		temp = temp ->next;
	}
}

void	get_cmd_args(t_cmd *cmd)
{
	t_list	*temp;
	char	*arg;

	temp = cmd->ex_elements->next;
	while (temp)
	{
		if (!ft_is_redi((((char *)temp ->content)[0])))
		{
			arg = ft_strdup((char *)temp->content);
			if (!arg)
			{
				chstatus(MEMORY_LACK, NULL, 30);
				return ;
			}
			if (!ft_lst_contain (&cmd->in_redirect_f, arg)
				&& !ft_lst_contain (&cmd->out_redirect_f, arg))
				ft_lstadd_back(&cmd->args, ft_lstnew(arg, CHAR));
			else
				free(arg);
		}
		temp = temp ->next;
	}
}

int	get_f_cmd(t_cmd *cmd, char *t_command)
{
	if (ft_strcmp("", cmd->cmd_str))
	{
		cmd ->f_cmd = ft_split (cmd->cmd_str, ' ');
		if (!cmd ->f_cmd)
		{
			chstatus(MEMORY_LACK, NULL, 30);
			if (t_command)
				free(t_command);
			return (0);
		}
	}
	return (1);
}

t_cmd	*get_cmd_data(char *command)
{
	t_cmd	*cmd;
	char	*t_command;

	cmd = ft_init_cmd ();
	if (!cmd || *(g_data.status.exit_code))
		return (cmd);
	command = if_prenthesized(command, &t_command);
	if (check_syntax(cmd, command) && (*g_data.status.exit_code))
	{
		if (t_command)
			free(t_command);
		return (cmd);
	}
	get_cmd(cmd);
	get_cmd_redirects(cmd);
	get_cmd_args(cmd);
	build_cmd (cmd);
	if (!get_f_cmd(cmd, t_command))
		return (NULL);
	add_path(cmd, t_command);
	
	return (cmd);
}
