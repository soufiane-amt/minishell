/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_rebuilt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelmoham <eelmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 14:58:46 by samajat           #+#    #+#             */
/*   Updated: 2022/04/19 21:35:27 by eelmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_rebuilt_cmd(t_data *data, t_cmd *cmd)
{
	int	result;

	result = is_rebuilt_cmd(cmd);
	if (result == 0)
		strerror(127);
	if (result == 1)
		ft_cd(data,cmd);
	if (result == 2)
		ft_echo(data, cmd);
	if (result == 3)
		ft_env(data, 1);
	if (result == 4)
		ft_export(data, cmd);
	if (result == 5)
		printf("%s\n",ft_pwd(data));
	if (result == 6)
		ft_unset(data, cmd);
	if (result == 7)
		ft_exit(data, cmd);
}