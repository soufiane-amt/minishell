/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelmoham <eelmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 15:03:40 by samajat           #+#    #+#             */
/*   Updated: 2022/05/24 20:17:00 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int is_exist(char *var, char *val)
{
	t_env *temp;

	temp = data.enver;
	while (temp)
	{
		if (!ft_strcmp(temp->variable, var))
		{
			temp->value = val;
			return (1);
		}
		temp = temp->next;
	}
	return (0);
}

void func(char *var , char *val)
{
	if (is_exist(var, val) == 0)
		ft_env_tadd_back(&(data.enver), ft_env_new(var, val));
	else
		if (!val && var)
			ft_env_tadd_back(&(data.enver), ft_env_new(var, ft_strdup(" ")));
}

void    ft_export(t_cmd *cmd)
{
	char *var;
	char *val;
	t_list *l;

	l = cmd->args;
	if (ft_lstsize(cmd->args) == 0)
		ft_env(0);
	while (l)
	{
		var = malloc(size_var_val(l->content, 1, '=') + 1);
		val = malloc(size_var_val(l->content, 0, '=') + 1);
		if (!var || !val)
		{
			chstatus(MEMORY_LACK, NULL, 30);
			return ;
		}
		else
		{   
			cpy_var_val(l->content, var, val, '=');
			func(var ,val);
		}
		l = l->next;
	}
	// printf("****> %s\n", ft_env_last(data.enver)->variable);
}
