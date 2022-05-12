/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctl_c.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 12:15:27 by eelmoham          #+#    #+#             */
/*   Updated: 2022/04/21 15:53:06 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// void ctl_c(int sig)
// {
//     struct termios    nt;
//     if (sig == SIGINT)
//     {
//         printf("\r");
//         rl_on_new_line();
//         rl_redisplay();
//         printf("\n");
//         rl_on_new_line();
//         rl_replace_line("", 0);
//         rl_redisplay();
//         nt.c_lflag &= ~(ECHOCTL);
//         *(data.status.exit_code) = 128 + sig;
//     }
//     if (sig == SIGQUIT)
//     {
//         *(data.status.exit_code) = 128 + sig;
//         exit(1);
//     }//we should use exit function for free 
//     nt.c_lflag |= ECHOCTL;
// }

void ctl_c(int sig)
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
    }
    if (sig == SIGQUIT)
        exit(1);
}
