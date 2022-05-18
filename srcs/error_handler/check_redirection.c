/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_redirection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelmoham <eelmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 17:11:56 by samajat           #+#    #+#             */
/*   Updated: 2022/05/18 16:38:54 by eelmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	input_redirection_is_valid(char *cmd)
{
	int	i;
	int	j;
	int	cmd_size;

	i = 0;
	j = 0;
	cmd_size = ft_strlen(cmd);
	while (cmd[i] != '<')
	{
		i++;
		if (i == cmd_size)
			return (1);
	}
	j = i;
	if (cmd[j] && cmd[j] == '<')
	{
		if (cmd[j + 1] && cmd[j + 1] == '<')
		{
			j++;
			while (cmd[j] && ft_ispace(cmd[j]))
				j++;
			if (cmd[j] && (cmd[j] == '<' || cmd[j] == '|'))
				return (0);
		}
	}
	return (1);
}

int	output_redirection_is_valid(char	*cmd)
{
	int	i;
	int	j;
	int	cmd_size;

	i = 0;
	j = 0;
	cmd_size = ft_strlen(cmd);
	while (cmd[i] != '>')
	{
		i++;
		if (i == cmd_size)
			return (1);
	}
	j = i;
	if (cmd[j] && cmd[j] == '>')
	{
		if (cmd[j + 1] && cmd[j + 1] == '>')
		{
			j++;
			while (cmd[j] && ft_ispace(cmd[j]))
				j++;
			if (cmd[j] && (cmd[j] == '>' || cmd[j] == '|'))
				return (0);
		}
	}
	return (1);
}
