/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _char.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelmoham <eelmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 13:51:36 by eelmoham          #+#    #+#             */
/*   Updated: 2022/05/14 14:37:01 by eelmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void expand_quotes(char *str)
{
	int i;
	int is_first;

	i = 0;
	is_first = who_first(str);
	while (str[i])
	{
		if (str[i] == '"' && is_first == 1)
			str[i] = -6;
		if (str[i] == '\'' && is_first == 0)
			str[i] = -5;
		if (str[i] == '$' && is_first != 0)// && sh_expand(str, '\'') != 0
			str[i] = -7;
		i++;
	}
}
static char *last(char *str)
{
	int i;
	char *var;
	char *st;

	i = 0;
	st = strdup("");
	while(str[i])
	{
		printf("***> %c\n", str[i]);
		if (str[i] == -7)
		{
			var = malloc(size_var(str, '$') + 1);
			i+= cpy_var(&str[i], var, -7);
			if (!getenv(var))
				st = ft_strjoin(st, "");
			else
				st = ft_strjoin(st, getenv(var));
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

	c = NULL;
	if (who_first(str) == 1)
		c = '"';
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
		return "syntax error";
	new_str = last(str);
	_last = NULL;
	while (new_str[i])
	{
		if (new_str[i] != -5 && new_str[i] != -6)
			_last = ft_charjoin(_last, new_str[i]);
		i++;
	}
	_last[i] = '\0';
	return (_last);
}

// int main()
// {
// 	char *str;
// 	char *newst;
// 	str = strdup("$USER");
// 	newst = _char(str);
// 	printf("%s\n", newst);
// }