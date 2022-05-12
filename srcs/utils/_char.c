/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _char.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelmoham <eelmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 13:51:36 by eelmoham          #+#    #+#             */
/*   Updated: 2022/05/12 17:06:45 by eelmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int who_first(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if(str[i] == '\'')
			return (0);
		if (str[i] == '"')
			return (1);
		i++;
	}
	return (-1);
}

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

static int go(char *str)
{
	char c;
	
	c = ' ';
	if (who_first(str) == 1)
		c = '"';
	else if (who_first(str) == 0)
		c = '\'';
	if (who_first(str) == -1)
		return (1);
	else if (sh_expand(str, c) == -1 || sh_expand(str, c) == 1)
		return (1);
	else if (sh_expand(str, c) == 0)
		return (-1);
	return (1);
}

static char *last(char *str, t_data *data)
{
	int i;
	char *var;
	char *st;

	i = 0;
	st = strdup("");
	while(str[i])
	{
		if (str[i] == -7)
		{
			var = malloc(size_var(str, '$') + 1);
			i+= cpy_var(&str[i], var, -7);
			st = ft_strjoin(st, get_var(data, var));
			free(var);
		}
		else
			st = ft_charjoin(st,str[i]);
		i++;
	}
	return(st);
}

char *_char(char *str, t_data *data)
{
	int i;
	char *new_str;
	int is_first;
	char *_last;

	i = 0;
	is_first = who_first(str);
	new_str = NULL;
	if (go(str) != -1)
		expand_quotes(str);
	else
		return "syntax error";
	new_str = last(str, data);
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

int is_ex(char *str)
{
    int i = 0;
    int is1 = -1;
    int is2 = -1;
    
    while(str[i])
    {
        if (str[i] == '\"')
        {
            if (is1 == -1)
				is1 = 0;
			else if (is1 == 0)
				is1 = 1;
			else if (is1 == 1)
				is1 = 0;
        }
        if (str[i] == '\'')
        {
            if (is2 == -1)
				is2 =  is1;
			else if (is2 == 0)
				is2 = 1 + is1;
			else if (is2 == 1)
				is2 = 0;
        }
        i++;
    }
    printf("%d %d\n", is1, is2);
    if(is2 > 1)
        return(0);
    if (is2 == 0 && is1 == 1)
        return (1);
    
}