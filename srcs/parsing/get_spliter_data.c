/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_spliter_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 14:50:44 by samajat           #+#    #+#             */
/*   Updated: 2022/04/25 01:48:06 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int     ft_is_sep(t_spliter *spliter, char  c)
{
    if (c == PIPE && !data.status.status)
    {
        pipe(spliter->pipe);
        //protection
        data.process_nbr++;
        return (1);
    }
    return (0);
}

//Don't forget to protect all strdup returning NULL
char    **get_two_separated_cmd(char *str, char sep)
{
    char    **two_cmd;

    if (!str)
        chstatus(MEMORY_LACK, NULL, 30);
    if (*data.status.exit_code)
        return (NULL);
    two_cmd = ft_split (str, sep);
    if (!two_cmd)
    {
        chstatus(MEMORY_LACK, NULL, 30);
        free(str);
        return (NULL);
    }
    free (str);
    return (two_cmd);
}

int get_spliter_data(t_spliter *spliter, char  *prev_cmd, char *next_cmd)
{
    static t_cmd *prevCmd;

    if (!data.call_nbr)
        spliter->Prevcmd = get_cmd_data(prev_cmd);
    else
        spliter->Prevcmd = prevCmd;
    spliter->Nextcmd = get_cmd_data(next_cmd);
    prevCmd = spliter -> Nextcmd;
    if (spliter ->spec_char == PIPE && !data.status.status)
    {
        spliter ->Prevcmd->output.fd = spliter->pipe[1];
        spliter ->Nextcmd->input.fd = spliter->pipe[0];
        open_redir_files(spliter->Prevcmd);
        open_redir_files(spliter->Nextcmd);
        ft_lstadd_back(&data.fds , ft_lstnew(&spliter->pipe[1], INT));
        ft_lstadd_back(&data.fds , ft_lstnew(&spliter->pipe[0], INT));
    }
    else
    {
        return (0);
    }
    data.call_nbr++;
    return (1);
}
//who | awk '{print $1}' | sort | uniq -c | sort -n
//define the file descriptor of output and input based on pipe and it is last data to assign

t_spliter *ft_split_by_sep()
{
    t_spliter   *spliter;
    char        **cmd;

    spliter = malloc (sizeof(t_spliter));
    if (!spliter)
    {
        chstatus(MEMORY_LACK, NULL, 30);
        return (NULL);
    }
    spliter->Prevcmd = NULL;
    spliter->Nextcmd = NULL;
    while (data.input[data.i])
    {
        if (ft_is_sep(spliter, data.input[data.i]))
        {
            data.l = data.i + 1;
            spliter->spec_char = data.input[data.i];
            while (data.input[data.l] && data.input[data.l] != '\n' && data.input[data.l] != spliter->spec_char)
                data.l++;
            cmd = get_two_separated_cmd(ft_substr(data.input, data.j, data.l + 1), spliter->spec_char);
            if (!cmd || *data.status.exit_code || !get_spliter_data(spliter, cmd[0], cmd[1]))
            {
                free_arr((void **)cmd);
                data.spliter_sucess = 0;
                return (spliter);
            }
            free_arr((void **)cmd);
            (data.i)++;
            data.j = data.i;
            return (spliter);
        }
        (data.i)++;
    }
    free(spliter);
    return (NULL);
}
