/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelmoham <eelmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 22:08:51 by eelmoham          #+#    #+#             */
/*   Updated: 2022/05/27 01:09:38 by eelmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_env(t_cmd *cmd, int is)
{
	t_env	*e;

	(void)cmd;
	e = g_data.enver;
	while (e)
	{
		if (!ft_strcmp(e->value, "") && !ft_strcmp(e->value, ""))
		{
			e = e->next;
			continue ;
		}
		if (is == 1 && ft_strcmp(e->value, ""))
			printf("%s=%s\n", e->variable, e->value);
		if (is == 0)
		{
			if (ft_strcmp(e->value, ""))
				printf("declare -x %s=%s\n", e->variable, e->value);
			else
				printf("declare -x %s\n", e->variable);
		}
		e = e->next;
	}
}
