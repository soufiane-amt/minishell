/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_built_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 13:38:28 by samajat           #+#    #+#             */
/*   Updated: 2022/05/14 18:50:59 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_built_cmd(t_cmd *cmd)
{
    if(!ft_strcmp(cmd->cmd, _char("unset")) || !ft_strcmp(cmd->cmd, _char("UNSET")))
		return (1);
	else if(!ft_strcmp(cmd->cmd, _char("echo")) || !ft_strcmp(cmd->cmd, _char("ECHO")))
		return (2);
	else if(!ft_strcmp(cmd->cmd, _char("env")) || !ft_strcmp(cmd->cmd, _char("ENV")))
		return (3);
	else if(!ft_strcmp(cmd->cmd, _char("export")) || !ft_strcmp(cmd->cmd, _char("EXPORT")))
		return (4);
	else if(!ft_strcmp(cmd->cmd, _char("pwd")) || !ft_strcmp(cmd->cmd, _char("PWD")))
		return (5);
    else if(!ft_strcmp(cmd->cmd, _char("cd")) || !ft_strcmp(cmd->cmd, _char("CD")))
		return (6);
	else if(!ft_strcmp(cmd->cmd, _char("exit")) || !ft_strcmp(cmd->cmd, _char("EXIT")))
		return (7);
	return (0);
}