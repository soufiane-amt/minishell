/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_built.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelmoham <eelmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 14:58:46 by samajat           #+#    #+#             */
/*   Updated: 2022/05/27 01:33:10 by eelmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_built_cmd(t_cmd *cmd, int result)
{
	if (result == 1)
		ft_echo(cmd);
	if (result == 2)
	{
		if (ft_lstsize(cmd->args) != 0)
			notify_error(TOO_MANY_ARGS, NULL);
		else
			printf("%s\n", ft_pwd());
	}
	if (result == 3)
	{
		if (cmd->args)
			perror(TOO_MANY_ARGS);
		else
			ft_env(cmd, 1);
	}
	if (result == 4 || result == 5)
		ft_export(cmd);
	if (result == 6)
		ft_cd(cmd);
	if (result == 7)
		ft_unset(cmd);
	if (result == 8)
		ft_exit();
}
