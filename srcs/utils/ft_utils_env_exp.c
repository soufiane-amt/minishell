/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_env_exp.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 23:01:56 by samajat           #+#    #+#             */
/*   Updated: 2022/05/25 20:03:42 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_env(char *var)
{
	t_env	*e;

	e = g_data.enver;
	while (e)
	{
		if (!ft_strcmp(e->variable, var))
		{
			return (e->value);
			break ;
		}
		e = e->next;
	}
	return ("");
}

void	cpy_var_val(char *str, char *var, char *val, char c)
{
	int	i;
	int	j;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	j = i + 1;
	while (str[j])
		j++;
	i = 0;
	while (str[i] && str[i] != c)
	{
		var[i] = str[i];
		i++;
	}
	var[i] = '\0';
	j = i + 1;
	i = 0;
	while (str[j])
		val[i++] = str[j++];
	val[i] = '\0';
}

void	get_env_while_prompt(char c, char **env)
{
	int		i;
	char	*var;
	char	*val;

	i = 0;
	g_data.env = env;
	while (g_data.env[i])
	{
		var = malloc(size_var_val(g_data.env[i], 1, c) + 1);
		val = malloc(size_var_val(g_data.env[i], 0, c) + 1);
		if (var && val)
		{
			cpy_var_val(g_data.env[i], var, val, '=');
			if (i == 0)
				g_data.enver = ft_env_new(var, val);
			else
				ft_env_tadd_back(&(g_data.enver), ft_env_new(var, val));
		}
		else
			return ;
		i++;
	}
}

int	size_var_val(char *str, int x, char c)
{
	int	i;

	i = 0;
	if (x == 1)
	{
		while (str[i] && str[i] != c)
			i++;
		return (i);
	}
	else if (ft_strchr(str, c) && ft_strchr(str, c) + 1)
		return (ft_strlen(ft_strchr(str, c) + 1));
	else
		return (0);
}

int	count_c(char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == c)
			count++;
		i++;
	}
	return (count);
}
