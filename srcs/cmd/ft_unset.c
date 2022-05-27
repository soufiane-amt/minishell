/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelmoham <eelmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 15:03:57 by samajat           #+#    #+#             */
/*   Updated: 2022/05/27 01:33:55 by eelmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_id(char *var)
{
	if ((var[0] >= 'a' && var[0] <= 'z')
		|| (var[0] >= 'A' && var[0] <= 'Z') || var[0] == '_')
		return (1);
	return (0);
}

void	ft_unset(t_cmd *cmd)
{
	t_env	*e;
	t_list	*arg;

	arg = cmd->args;
	if (!arg)
		return ;
	while (arg)
	{
		if (is_id((char *)arg->content) == 0)
			chstatus("not a valid identifier\n", NULL, 1);
		e = g_data.enver;
		while (e)
		{
			if (!ft_strcmp(e->variable, (char *)arg->content))
			{
				free(e->value);
				free(e->variable);
				e->value = ft_strdup("");
				e->variable = ft_strdup("");
			}
			e = e->next;
		}
		arg = arg->next;
	}
}
