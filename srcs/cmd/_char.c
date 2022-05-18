/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _char.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 13:51:36 by eelmoham          #+#    #+#             */
/*   Updated: 2022/05/18 23:14:33 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	expand_quotes(char *str)
{
	int	i;
	int	is_first;

	i = 0;
	is_first = who_first(str);
	while (str[i])
	{
		if (str[i] == '"' && is_first == 1)
			str[i] = -6;
		if (str[i] == '\'' && is_first == 0)
			str[i] = -5;
		if ((str[i] == '$') && (is_first == 0
					&& really(str, i) != 0))
			str[i] = -7;
		else if (str[i] == '$' && is_first != 0)
			str[i] = -7;
		i++;
	}
}

char	*last(char *str)
{
	int		i;
	char	*var;
	char	*st;

	i = 0;
	st = ft_strdup("");
	while (str[i])
	{
		if (str[i] == -7)
		{
			var = malloc(size_var(str, '$') + 1);
			if (!var)
			{
				chstatus(MEMORY_LACK, NULL, 30);
				return (NULL);
			}
			i = i + cpy_var(&str[i], var, -7);
			get_value_from_enver(&st, var);
		}
		else
			st = ft_charjoin(st, str[i]);
		i++;
	}
	return (st);
}

static	int	go(char *str)
{
	char	c;

	c = 0;
	if (who_first(str) == 1)
		c = '\"';
	else if (who_first(str) == 0)
		c = '\'';
	if (who_first(str) == -1)
		return (1);
	else if (is_ex12(str, c) == -1 || is_ex12(str, c) == 1)
		return (1);
	else if (is_ex12(str, c) == 0)
		return (-1);
	return (1);
}

char	*_char(char *str)
{
	int i;
	int j;
	char *new_str;
	int is_first;
	char *_last;

	
	i = 0;
	j = 0;
	is_first = who_first(str);
	new_str = NULL;
	if (go(str) != -1)
		expand_quotes(str);
	else
	{
		chstatus(SYNTAX_ERROR, NULL, 30);
		return (NULL);
	}
	new_str = last(str);
	_last = ft_strdup("");
	if (!_last)
	{
		chstatus(SYNTAX_ERROR, NULL, 30);
		return (NULL);
	}
    puts("--------\n");
	if (ft_expand(&_last, new_str) < 0)
		return (NULL);
	if (!ft_strcmp(_last, " "))
		_last = ft_strdup("");	
	if (!_last)
	{
		chstatus(MEMORY_LACK, NULL, 55);
		return (NULL);
	}
	return (_last);
}