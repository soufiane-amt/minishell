/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_rebuilt_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelmoham <eelmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 13:38:28 by samajat           #+#    #+#             */
/*   Updated: 2022/04/19 21:33:50 by eelmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_rebuilt_cmd(t_cmd *cmd)
{
	if(!ft_strcmp(cmd->cmd, "cd") || !ft_strcmp(cmd->cmd, "CD"))
		return (1);
	else if(!ft_strcmp(cmd->cmd, "echo") || !ft_strcmp(cmd->cmd, "ECHO"))
		return (2);
	else if(!ft_strcmp(cmd->cmd, "env") || !ft_strcmp(cmd->cmd, "ENV"))
		return (3);
	else if(!ft_strcmp(cmd->cmd, "export") || !ft_strcmp(cmd->cmd, "EXPORT"))
		return (4);
	else if(!ft_strcmp(cmd->cmd, "pwd") || !ft_strcmp(cmd->cmd, "PWD"))
		return (5);
	else if(!ft_strcmp(cmd->cmd, "unset") || !ft_strcmp(cmd->cmd, "UNSET"))
		return (6);
	else if(!ft_strcmp(cmd->cmd, "exit") || !ft_strcmp(cmd->cmd, "EXIT"))
		return (7);
	return (0);
}