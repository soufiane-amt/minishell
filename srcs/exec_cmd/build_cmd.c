/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 21:41:21 by samajat           #+#    #+#             */
/*   Updated: 2022/05/16 21:51:31 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    add_space (char **cmd)
{
    char    *f_str;

    f_str = *cmd;
    *cmd = ft_strjoin (*cmd, " ");
    if (!(*cmd))
    {
        chstatus(MEMORY_LACK, NULL, 30);
        return ;
    }
    free (f_str);
}

void    add_comp(t_cmd  *cmd, t_list    *temp)
{
    char    *f_str;

    if (!ft_is_redi((((char *)temp ->content)[0]))  &&
        !ft_lst_contain (&cmd->in_redirect_f, (char *)temp ->content) &&
        !ft_lst_contain (&cmd->out_redirect_f, (char *)temp ->content))
    {
    f_str = cmd->cmd_str;
    cmd->cmd_str = ft_strjoin (cmd->cmd_str, (char *)temp ->content);
    if (!cmd->cmd_str)
    {
        chstatus(MEMORY_LACK, NULL, 30);
        return ;
    }
    add_space(&cmd->cmd_str);
    if (*data.status.exit_code)
        return;
    free(f_str);
    }
}

void build_cmd (t_cmd *cmd)
{
    t_list  *temp;

    cmd->cmd_str = ft_strdup("");
    if (!cmd->cmd_str)
    {
        chstatus(MEMORY_LACK, NULL, 30);
        return ;
    }
    temp = cmd->ex_elements;
    while (temp)
    {
        add_comp(cmd, temp);
        temp = temp ->next;
    }
}
