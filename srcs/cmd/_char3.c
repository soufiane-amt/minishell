/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _char3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelmoham <eelmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 14:35:20 by eelmoham          #+#    #+#             */
/*   Updated: 2022/05/18 18:54:15 by eelmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	get_value_from_enver(char **st, char *var)
{
	char	*forfree;

	if (!ft_strcmp(var, "?"))
	{
		forfree = *st;
		*st = ft_strjoin(*st, ft_itoa(data.status.exit_code));
		free(forfree);
	}
	else if (!getenv(var))
	{
		forfree = *st;
		*st = ft_strjoin(*st, "");
		free(forfree);
	}
	else
	{
		forfree = *st;
		*st = ft_strjoin(*st, get_env(var));
		free(forfree);
	}
}

int	really(char *str, int to)
{
	int	i;
	int	is;

	i = 0;
	is = -1;
	while (str[i] && i <= to)
	{
		if (str[i] == '\'')
		{
			if (is == -1)
				is = 0;
			else if (is == 0)
				is = 1;
			else if (is == 1)
				is = -1;
		}
		i++;
	}
	return (is);
}

int	func_is1(char *str)
{
	int	i;
	int	is;
	int	count;

	count = 0;
	i = 0;
	is = -1;
	while (str[i])
	{
		if (str[i] == '\'')
		{
			if (is == -1)
				is = 0;
			else if (is == 0)
				is = 1;
			else if (is == 1)
				is = 0;
		}
		if (str[i] == '\"' && is == 1)
			count++;
		i++;
	}
	if (is == 1 && count % 2 == 0)
		return (1);
	return (0);
}

int	func_is2(char *str)
{
	int	i;
	int	is;
	int	count;

	count = 0;
	i = 0;
	is = -1;
	while (str[i])
	{
		if (str[i] == '\"')
		{
			if (is == -1)
				is = 0;
			else if (is == 0)
				is = 1;
			else if (is == 1)
				is = 0;
		}
		if (str[i] == '\'' && is == 1)
			count++;
		i++;
	}
	if (is == 1 && count % 2 == 0)
		return (1);
	return (0);
}

int	is_ex12(char *str, char c)
{
	if (c == '\'')
		return (func_is1(str));
	if (c == '\"')
		return (func_is2(str));
	else
		return (-1);
}
