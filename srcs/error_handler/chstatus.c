/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chstatus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelmoham <eelmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 00:29:21 by samajat           #+#    #+#             */
/*   Updated: 2022/05/17 22:03:22 by eelmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//the system has a lack of  memory, please free up some space and try again!
void    ch_to_error_message_only(char   *exit_message)
{
    data.status.status = ft_strjoin(exit_message, "\n");
    if (!data.status.status)
    {
        data.status.exit_code = 30;
        return ;
    }
}

//the system has a lack of  memory, please free up some space and try again!
void chstatus (char *exit_message, char *cmd, int   exit_code)
{
    char    *to_free;

    (void)to_free;
    if (!data.status.exit_code)    
    {
        data.status.exit_code = exit_code;
        if (cmd)
        {
            to_free = ft_strjoin(exit_message, cmd);
            if (!to_free)
            {
                data.status.exit_code = 30;
                return ;            
            }
            data.status.status = ft_strjoin(to_free, "\n");
            if (!data.status.status)
            {
                data.status.exit_code = 30;
                return ;
            }
            free(to_free);
            return ;
        }
        ch_to_error_message_only(exit_message);
    }
}
