/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd_ln.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 00:39:59 by samajat           #+#    #+#             */
/*   Updated: 2022/04/24 23:50:33 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// void     clos (int  sig)
// {
//     // fprintf (stderr ,"cmd->input.fd = %d\ncmd->output.fd = %d\n", cmd->input.fd, cmd->output.fd);
//     // close (cmd->input.fd);
//     // close (cmd->output.fd);
//     if (sig == SIGPIPE)
//         close(0);
// }

void    exec_cmd_ln(t_token **token)
{
    t_token *temp;
    t_cmd   *one_cmd;
    int         i;

    if (*data.status.exit_code)
        return ;
    if ( !data.input_piped)
    {
        one_cmd = get_cmd_data (data.input);
        if (*data.status.exit_code)
        {
            free_cmd(one_cmd);
            return ;
        }
        open_redir_files(one_cmd);
        exec_cmd(one_cmd);
        waitpid(-1, NULL, 0);
        free_cmd(one_cmd);
    }
    else
    {
        i = 0;
        temp = *token;
        while (temp)
        {
            if (!(i++))
                exec_cmd(temp->sep->Prevcmd);
            exec_cmd(temp->sep->Nextcmd);
            temp = temp ->next;
        }
        while (waitpid(-1, NULL, 0) != -1);
    }
}
// void    exec_cmd_ln(, t_token **token, t_token *temp)
// {
//     t_token         *temp;
//     static int         i;

//     i = 0;
//     temp = *token;
//     if (temp)
//         return ;
//     if (!(i++))
//         exec_cmd_ln(data, temp->sep->Prevcmd, temp->next);
//     exec_cmd_ln(data, temp->sep->Nextcmd, temp->next);
//     // waitpid(-1, NULL, 0);
// }