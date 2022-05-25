/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_user_input.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 18:56:03 by samajat           #+#    #+#             */
/*   Updated: 2022/05/25 19:24:11 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	cmd_piped()
{
	int	i;
	int	j;
	int	quotes_pre;
	int	quotes_aft;

	i = 0;
	j = ft_strlen(data.input) - 1;
	quotes_pre = 0;
	quotes_aft = 0;
	while (data.input[i] && data.input[i] != '|')
	{
		if (data.input[i] == '\'')
			quotes_pre++;
		i++;
	}
	while (j >= 0 && data.input[j] != '|')
	{
		if (data.input[j] == '\'')
			quotes_aft++;
		j--;
	}
	if(quotes_aft == quotes_pre && quotes_aft == 1)
		return (0);
	return (1);
}
int	cmd_piped2()
{
	int	i;
	int	j;
	int	quotes_pre;
	int	quotes_aft;

	i = 0;
	j = ft_strlen(data.input) - 1;
	quotes_pre = 0;
	quotes_aft = 0;
	while (data.input[i] && data.input[i] != '|')
	{
		if (data.input[i] == '\"')
			quotes_pre++;
		i++;
	}
	while (j >= 0 && data.input[j] != '|')
	{
		if (data.input[j] == '\"')
			quotes_aft++;
		j--;
	}
	if(quotes_aft == quotes_pre && quotes_aft == 1)
		return (0);
	return (1);
}

int	check_user_input(char *str)
{
	if ((*data.status.exit_code))
		return (0);
	if (!(str) || !ft_strcmp(str, ""))
		return (0);
	if (str[0] == '|' || str[ft_strlen(str) - 1] == '|')
	{
		chstatus(SYNTAX_ERROR, "|", 258);
		return (0);
	}
	return (1);
}
