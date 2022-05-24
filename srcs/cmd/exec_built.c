/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_built.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 14:58:46 by samajat           #+#    #+#             */
/*   Updated: 2022/05/23 23:19:47 by samajat          ###   ########.fr       */
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
		ft_unset(cmd);
	if (result == 4)
    {
        if (ft_lstsize(cmd->args) != 0)
            chstatus(TOO_MANY_ARGS, NULL, 1);
		else
		    ft_env(1);
    }
	if (result == 5)
		ft_export(cmd);
	if (result == 6)
	    ft_cd(cmd);
	if (result == 7)
		ft_exit(cmd);
}
