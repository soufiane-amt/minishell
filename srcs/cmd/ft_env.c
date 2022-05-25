/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 22:08:51 by eelmoham          #+#    #+#             */
/*   Updated: 2022/05/25 20:03:42 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_env(int is)
{
	t_env	*e;

	e = g_data.enver;
	while (e)
	{
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
