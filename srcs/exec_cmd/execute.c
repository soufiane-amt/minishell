/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 21:13:23 by samajat           #+#    #+#             */
/*   Updated: 2022/05/15 19:57:32 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void     close_fd (t_cmd *cmd,int    close_all)
{
    t_list *temp;

    if (!close_all)
    {
        if (cmd->input.fd != STDIN_FILENO)
            close (cmd->input.fd);
        if (cmd->output.fd != STDOUT_FILENO)
            close (cmd->output.fd);
    }
    else
    {
        temp = data.fds;
        while (temp)
        {
            if (*((int *)temp->content) > 2)
                close(*((int *)temp->content));
            temp =temp->next;
        }
    }
}

void    exec_cmd (t_cmd *cmd)
{
    int         id;
    int         cmd_type;

    id = fork();
    if (id < 0)
        return ;
    cmd_type = is_built_cmd(cmd);
    //mind the exit!!!!!!!!!
    if (id == 0 && cmd_type < 6)
    {
        *(data.status.exit_code) = 0;
        if (cmd->input.fd != STDIN_FILENO)
            dup2 (cmd->input.fd, STDIN_FILENO);
        if (cmd->output.fd != STDOUT_FILENO)
            dup2 (cmd->output.fd, STDOUT_FILENO);
        close_fd(cmd, 1);
        if (!cmd_type) 
            execve (cmd->f_cmd[0], cmd->f_cmd, data.env);
        else
            exec_built_cmd(cmd);
        *(data.status.exit_code) = 1;
        exit(1);
    }
    else
    {
        exec_built_cmd(cmd);
    }
    close_fd(cmd, 0);
}
