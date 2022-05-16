/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 13:20:39 by samajat           #+#    #+#             */
/*   Updated: 2022/05/16 22:29:49 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void ft_echo(t_cmd *cmd)
{
    t_list *arg;
	int is_nl;

	is_nl = 0;
    arg = cmd->args;
	if (arg && !ft_strcmp(arg->content, "-n"))
	{
		is_nl = 1;
		arg = arg->next;
	}
    while(arg)
    {	
		printf("%s ",arg->content);
        arg = arg->next;
    }
	if (is_nl == 0)
        printf ("\n");
	//error = 1
}