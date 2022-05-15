/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_built.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 14:58:46 by samajat           #+#    #+#             */
/*   Updated: 2022/05/15 19:57:43 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_built_cmd(t_cmd *cmd)
{
	int	result;

	result = is_built_cmd(cmd);
    printf("------------------\n");
	if (result == 1)
		ft_unset(cmd);
	if (result == 2)
		ft_echo(cmd);
	if (result == 3)
		ft_env(cmd, 1);
	if (result == 4)
		ft_export(cmd);
	if (result == 5)
		printf("%s\n",ft_pwd());
	if (result == 6)
    	ft_cd(cmd);
	if (result == 7)
		ft_exit(cmd);
}