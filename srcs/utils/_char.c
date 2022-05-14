/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _char.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelmoham <eelmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 13:51:36 by eelmoham          #+#    #+#             */
/*   Updated: 2022/05/14 13:08:17 by eelmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		s1_s;
	int		s2_s;

	i = 0;
	s1_s = strlen(s1);
	s2_s = strlen(s2);
	str = (char *) malloc (sizeof(char) * (s1_s + s2_s + 1));
	if (!str)
		return (NULL);
	strlcpy(str, s1, s1_s + 1);
	while (i < s2_s)
	{
		str[s1_s] = (char)s2[i];
		s1_s++;
		i++;
	}
	str[s1_s] = 0;
	return (str);
}

static int size_var(char *str, char c)
{
	int i;
	int count;
	
	i = 0;
	count = 0;
	while(str[i])
	{
	  if (str[i] == c)
		  break;
	  i++;
	}
	if (str[i] == '$')
		i++;
	while ((str[i] && str[i] != c)
		&& ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z')))
	{
		count++;
		i++;

	}
	return (count);
}

static int  cpy_var(char *str, char *var, char c)
{
	int i;
	int j;
	
	i = 0;
	j = 0;
	while (str[i] && str[i] == c)
		i++;
	while (str[i] && str[i] != c && ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z')))
	{
		var[j] = str[i];
		i++;
		j++;
	}
	var[j] = '\0';
	return (strlen(var));
}

static char	*ft_one_char_str(char c)
{
	char	*output;

	output = (char *) malloc(2 * sizeof(char));
	if (!output)
		return (NULL);
	output[0] = c;
	output[1] = 0;
	return (output);
}

static char	*ft_charjoin(char *s1, char c)
{
	unsigned int	i;
	char			*output;

	if (!s1)
		return (ft_one_char_str(c));
	i = 0;
	output = (char *) malloc((strlen(s1) + 2) * sizeof(char));
	if (!output)
		return (NULL);
	while (s1[i])
	{
		output[i] = s1[i];
		i++;
	}
	output[i++] = c;
	output[i] = '\0';
	free(s1);
	s1 = NULL;
	return (output);
}

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

int func_is1(char *str)
{
    int i;
    int is;
    int count;
    
    count = 0;
    i = 0;
    is = -1;
    while (str[i])
    {
        if (str[i] == '\'')
        {
            if(is == -1)
                is = 0;
            else if(is == 0)
                is = 1;
            else if (is == 1)
                is = 0;
        }
        if (str[i] == '\"' && is == 1)
            count++;
        i++;
    }
    if (is == 1 && count % 2 == 0)
        return 1;
    return 0;
}
int func_is2(char *str)
{
    int i;
    int is;
    int count;
    
    count = 0;
    i = 0;
    is = -1;
    while (str[i])
    {
        if (str[i] == '\"')
        {
            if(is == -1)
                is = 0;
            else if(is == 0)
                is = 1;
            else if (is == 1)
                is = 0;
        }
        if (str[i] == '\'' && is == 1)
            count++;
        i++;
    }
    if (is == 1 && count % 2 == 0)
        return 1;
    return 0;
}

int is_ex12(char *str, char c)
{
    if (c == '\'')
        return(func_is1(str));
    if (c == '\"')
        return(func_is2(str));
    else
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