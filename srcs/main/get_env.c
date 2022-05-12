/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelmoham <eelmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 17:41:26 by eelmoham          #+#    #+#             */
/*   Updated: 2022/04/05 22:24:12 by eelmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
//this function for get all enverment variable :
void get_env_while_prompt(t_data *data,  char c)
{
    int i;
    char *var;
    char *val;

    i = 0;
    data->enver = NULL;
    while (data->env[i])
    {
        var = malloc(size_var_val(data->env[i], 1, c) + 1);
        val = malloc(size_var_val(data->env[i], 0, c) + 1);
        cpy_var_val(data->env[i], var, val, c);
        ft_env_tadd_back(&(data->enver), ft_env_new(var, val));
        i++;
    }
    free(var);
    free(val);
}
