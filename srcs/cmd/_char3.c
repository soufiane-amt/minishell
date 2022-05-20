/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _char3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelmoham <eelmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 14:35:20 by eelmoham          #+#    #+#             */
/*   Updated: 2022/05/20 14:03:19 by eelmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	get_value_from_enver(char **st, char *var)
{
	char	*forfree;
	char	*ffree;

	if (!ft_strcmp(var, "?"))
	{
		forfree = *st;
		ffree = ft_itoa(data.status.exit_code);
		*st = ft_strjoin(*st, ffree);
		free(forfree);
		free(ffree);
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
	free(var);
}

int	really(char *str, int to, char c)
{
	int	i;
	int	is;

	i = 0;
	is = -1;
	while (str[i] && i <= to)
	{
		if (str[i] == c)
		{
			if (is == -1)
				is = 0;
			else if (is == 0)
				is = 1;
			else if (is == 1)
				is = 0;
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
