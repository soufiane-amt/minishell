/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ctl_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelmoham <eelmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 12:35:53 by eelmoham          #+#    #+#             */
/*   Updated: 2022/03/28 13:40:16 by eelmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <editline/readline.h>
#include <stddef.h>
#include <signal.h>

void test_ctl_c(int sig)
{
    if (sig == SIGINT)
    {
        rl_replace_line(">", 0);
    }
}
int main ()
{
     char *cmd;
    while (1)
    {
        cmd = readline(">");
        add_history(cmd);
        if (access(cmd, W_OK) == 0)
            printf("%s\n",cmd);   
        signal(SIGINT,test_ctl_c);
    }
    return 0;
}