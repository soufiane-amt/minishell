/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelmoham <eelmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 12:15:27 by eelmoham          #+#    #+#             */
/*   Updated: 2022/04/19 20:41:47 by eelmoham         ###   ########.fr       */
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