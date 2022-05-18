/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelmoham <eelmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 15:03:57 by samajat           #+#    #+#             */
/*   Updated: 2022/05/18 14:45:52 by eelmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	is_ex(char *var, char *arg)
{
	if (!ft_strcmp(var, arg))
		return ;
	else if ((var[0] >= 'a' || var[0] >= 'z')
		&& (var[0] >= 'A' || var[0] <= 'Z'))
		printf("unset: `%s': not a valid identifier", var);
}

void	ft_unset(t_cmd *cmd)
{
	t_env	*e;
	t_list	*arg;
	char	*var;

	arg = cmd->args;
	if (!arg)
		return ;
	while (arg)
	{
		e = data.enver;
		while (e)
		{
			var = e->variable;
			is_ex(e->variable, arg->content);
			e = e->next;
		}
		if (e)
		{
			e->value = "";
			e->variable = "";
		}
		arg = arg->next;
	}
}
