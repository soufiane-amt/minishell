/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 22:55:56 by samajat           #+#    #+#             */
/*   Updated: 2022/05/12 22:55:57 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ctl_c(int sig)
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
        return (128 + sig);
    }
    if (sig == SIGQUIT)
        exit(128 + sig);//we should use exit function for free
}
