/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_built_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelmoham <eelmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 13:38:28 by samajat           #+#    #+#             */
/*   Updated: 2022/05/17 18:37:47 by eelmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}

static void lowerchar(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		str[i] = ft_tolower(str[i]);
		i++;
	}
}

int	is_built_cmd(t_cmd *cmd)
{
	lowerchar(cmd->cmd);
	if(!ft_strcmp(cmd->cmd, "echo"))
		return (1);
	else if(!ft_strcmp(cmd->cmd, "pwd"))
		return (2);
    else if(!ft_strcmp(cmd->cmd, "unset"))
		return (3);
	else if(!ft_strcmp(cmd->cmd, "env"))
		return (4);
	else if(!ft_strcmp(cmd->cmd, "export"))
		return (5);
    else if(!ft_strcmp(cmd->cmd, "cd"))
		return (6);
	else if(!ft_strcmp(cmd->cmd, "exit"))
		return (7);
	return (0);
}