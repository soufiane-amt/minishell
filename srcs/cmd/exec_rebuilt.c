/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_rebuilt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelmoham <eelmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 14:58:46 by samajat           #+#    #+#             */
/*   Updated: 2022/05/14 14:32:53 by eelmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_rebuilt_cmd(t_cmd *cmd)
{
	int	result;

	result = is_rebuilt_cmd(cmd);
	if (result == 0)
		strerror(127);
	if (result == 1)
		ft_cd(cmd);
	if (result == 2)
		ft_echo(cmd);
	if (result == 3)
		ft_env(1);
	if (result == 4)
		ft_export(cmd);
	if (result == 5)
		printf("%s\n",ft_pwd());
	if (result == 6)
		ft_unset(cmd);
	if (result == 7)
		ft_exit(cmd);
}