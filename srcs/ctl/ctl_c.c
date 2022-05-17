/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctl_c.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelmoham <eelmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 12:15:27 by eelmoham          #+#    #+#             */
/*   Updated: 2022/05/17 22:11:10 by eelmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void  ctl_c(int sig)
{
    if (sig == SIGINT)
    {
        printf("\r");
        rl_on_new_line();
        rl_redisplay();
        printf("\n");
        rl_on_new_line();
        rl_replace_line("", 0);
        rl_redisplay();
        data.status.exit_code = 128 + sig;
    }
    if (sig == SIGQUIT)
    {
        rl_on_new_line();
        rl_replace_line("", 0);
        rl_redisplay();
        data.status.exit_code = 0;
        return ;
    }//we should use exit function for free
    data.status.exit_code = 0;
}

