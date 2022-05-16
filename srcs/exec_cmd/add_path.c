/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:23:50 by samajat           #+#    #+#             */
/*   Updated: 2022/05/16 21:17:02 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// int    add_path(t_cmd *cmd)
// {
//     int     i;
//     char    *command;

//     if (ft_is_redirection (cmd->cmd))
//         return (0);
//     if (is_built_cmd(cmd))
//         return (0);
//     i = 0;
//     if (!cmd->f_cmd)
//         return (0);
//     if (!access(cmd->f_cmd[0], F_OK))
//     {
//         if (!access(cmd->f_cmd[0], X_OK))
//         {
//             return (1);
//         }
//         else
//         {
//             notify_error(PERMISSION_DENIED, cmd->cmd);
//             *(data.status.exit_code) = 126;
//             return (1);
//         }
//     }
//     while (data.all_paths[i])
//     {
//         command = cmd->f_cmd[0];
//         data.mypath = ft_strjoin (data.all_paths[i], command);
//         if (!data.mypath)
//         {
//             chstatus(MEMORY_LACK, NULL, 30);
//             return (0);
//         }
//         if (!access(data.mypath, F_OK))
//         {
//             if (!access(data.mypath, X_OK))
//             {
//                 cmd->f_cmd[0] = data.mypath;
//                 free (command);
//                 return (1);
//             }
//             else
//             {
//                 notify_error(PERMISSION_DENIED, cmd->cmd);
//                 *(data.status.exit_code) = 126;
//                 free (command);
//                 return (1);
//             }
//         }
//         free(data.mypath);
//         data.mypath = NULL;
//         i++;
//     }
//     notify_error(CMD_NOT_FOUND, cmd->cmd);
//     *(data.status.exit_code) = 127;
//     return (0);
// }
//free mypath in the data

int    file_is_executable (t_cmd *cmd, char    *command)
{
    if (!access(data.mypath, X_OK))
    {
        cmd->f_cmd[0] = data.mypath;
        free (command);
        return (0);
    }
    else
    {
        notify_error(PERMISSION_DENIED, cmd->cmd);
        *(data.status.exit_code) = 126;
        free (command);
        return (0);
    }
}

int     test_paths(t_cmd *cmd)
{
    int     i;
    char    *command;

    i = 0;
    while (data.all_paths[i])
    {
        command = cmd->f_cmd[0];
        data.mypath = ft_strjoin (data.all_paths[i], command);
        if (!data.mypath)
        {
            chstatus(MEMORY_LACK, NULL, 30);
            return (0);
        }
        if (!access(data.mypath, F_OK))
            if (!file_is_executable(cmd, command))
                return (0);
        free(data.mypath);
        data.mypath = NULL;
        i++;
    }
    return (1);
}

int    add_path(t_cmd *cmd)
{
    if (!cmd->f_cmd)
        return (0);
    if (!access(cmd->f_cmd[0], F_OK))
    {
        if (!access(cmd->f_cmd[0], X_OK))
        {
            return (1);
        }
        else
        {
            notify_error(PERMISSION_DENIED, cmd->cmd);
            *(data.status.exit_code) = 126;
            return (1);
        }
    }
    if (!test_paths(cmd))
        return (0);
    notify_error(CMD_NOT_FOUND, cmd->cmd);
    *(data.status.exit_code) = 127;
    return (0);
}
