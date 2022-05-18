/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_built.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelmoham <eelmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 14:58:46 by samajat           #+#    #+#             */
/*   Updated: 2022/05/18 14:21:42 by eelmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_built_cmd(t_cmd *cmd, int result)
{
	if (result == 1)
		ft_echo(cmd);
	if (result == 2)
		printf("%s\n", ft_pwd());
	if (result == 3)
		ft_unset(cmd);
	if (result == 4)
		ft_env(1);
	if (result == 5)
		ft_export(cmd);
	if (result == 6)
		ft_cd(cmd);
	if (result == 7)
		ft_exit(cmd);
}
