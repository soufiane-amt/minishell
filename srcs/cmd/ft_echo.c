/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelmoham <eelmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 13:20:39 by samajat           #+#    #+#             */
/*   Updated: 2022/05/14 14:52:07 by eelmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void ft_echo(t_cmd *cmd)
{
    t_list *arg;
	int is_nl;

	is_nl = 0;
    arg = cmd->args;
	if (!ft_strcmp(arg->content, "-n"))
		is_nl == 1;
    while(arg)
    {	
		printf("%s ",_char(arg->content));
        arg = arg->next;
    }
	if (is_nl == 1);
		printf("\n");
	//error = 1
    
}