/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _char.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 13:51:36 by eelmoham          #+#    #+#             */
/*   Updated: 2022/05/17 21:39:59 by samajat          ###   ########.fr       */
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
		if ((str[i] == '$') && (is_first != 0 || (is_first == 0
				&& really(str, i) != 0)))
			str[i] = -7;
		if ((str[i] == '?') && (is_first != 0 || (is_first == 0
				&& really(str, i) != 0)))
			str[i] = -8;
		i++;
	}
}
char *last(char *str)
{
	int i;
	char *var;
	char *st;

	i = 0;
	st = ft_strdup("");
	while(str[i])
	{
		if (str[i] == -7)
		{
			var = malloc(size_var(str, '$') + 1);
            if (!var)
            {
                chstatus(MEMORY_LACK, NULL, 30);
                return (NULL);
            }
			i+= cpy_var(&str[i], var, -7);
			// printf("* * * * > > %d\n", var[0]);
			if (!getenv(var))
				st = ft_strjoin(st, "");
			else
				st = ft_strjoin(st, get_env(var));
			free(var);
		}
		else
			st = ft_charjoin(st,str[i]);
		i++;
	}
	return(st);
}

static int go(char *str)
{
	char c;

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

char *_char(char *str)
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
		return ("syntax error");// not good here
	new_str = last(str);
	_last = ft_strdup("");
	while (new_str[i])
	{
		if (new_str[i] != -5 && new_str[i] != -6)
			_last = ft_charjoin(_last, new_str[i]);
		if (new_str[i] == -5 || new_str[i] == -6)
			j++;
		//free here
		i++;
	}
	_last[i - j] = '\0';
	if (!ft_strcmp(_last, " "))
		_last = ft_strdup("");
	return (_last);// what if its NULL
}