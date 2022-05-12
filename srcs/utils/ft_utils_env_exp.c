/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_env_exp.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 23:01:56 by samajat           #+#    #+#             */
/*   Updated: 2022/05/12 23:01:57 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"

void get_env_while_prompt( char c)
{
    int i;
    char *var;
    char *val;

    i = 0;
    data.enver = NULL;
    while (data.env[i])
    {
        var = malloc(size_var_val(data.env[i], 1, c) + 1);
        val = malloc(size_var_val(data.env[i], 0, c) + 1);
        cpy_var_val(data.env[i], var, val, '=');
        ft_env_tadd_back(&(data.enver), ft_env_new(var, val));
        i++;
    }
    free(var);
    free(val);
}

void cpy_var_val(char *str, char *var, char *val, char c)
{
    int i;
    int j;
    
    i = 0;
    while (str[i] && str[i] != c)
        i++;
    j = i+ 1;
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

int size_var_val(char *str, int x, char c)
{
    int i;
    
    i = 0;
    if (x == 1)
    {
        while (str[i] && str[i] != c)
            i++;
        return (i);
    }
    return (ft_strlen(ft_strchr(str, c)+1));
}

int count_c(char *str, char c)
{
    int i;
    int count;

    i = 0;
    count = 0;
    while(str[i])
    {
        if (str[i] == c)
            count++;
        i++;
    }
    return (count);
}

char *env_var(char *str)
{
    int i;
    char *s;
    
    i = count_c(str, '$') + count_c(str, '"');
    s = malloc((ft_strlen(str) - i) + 1);
    i = 0;
    int j = 0;
    if (str[0] == '"' || str[0] == '$' || (str[0] == '"' && str[1] == '$'))
    {
        while(str[i])
        {
            if (str[i] == '$' || str[i] == '"')
                i++;
            else
            {
                s[j] = str[i];
                j++;
                i++;
            }
        }
    }
    s[j] = '\0';
    return (s);
}
