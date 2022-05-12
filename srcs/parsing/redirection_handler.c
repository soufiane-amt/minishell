/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_handler.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 22:22:58 by samajat           #+#    #+#             */
/*   Updated: 2022/04/24 23:50:33 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void close_ancient_fd (int  old_fd)
{
    if (old_fd > 2)
        close (old_fd);
}

void open_redir_files_in(t_cmd *cmd)
{
    t_list          *temp;
    int             old_fd;

    if (*data.status.exit_code)
        return ;
    temp = cmd->in_redirect_f;
    if (data.input_piped)
        data.c++;
    while (temp)
    {
        old_fd = cmd->input.fd;
        if(ft_lst_contain(&cmd->heredoc_delimits, (char *)temp->content) && (data.c == 1 || data.c % 2 == 0 ))
        {
            ft_open_heredoc(cmd, (char *)temp->content);
        }
        else if (!ft_lst_contain(&cmd->heredoc_delimits, (char *)temp->content))
        {
            cmd->input.fd= open(temp->content, O_RDONLY , 0644);
            if (!cmd->input.fd)
                return ;
            close_ancient_fd(old_fd);
            ft_lstadd_back(&data.fds , ft_lstnew(&cmd->input.fd ,INT));
            //mind the exit
        }
        temp = temp -> next;
    }
}

void open_redir_files_ou(t_cmd *cmd)
{
    t_list          *temp;
    int             old_fd;

    if (*data.status.exit_code)
        return ;
    temp = cmd->out_redirect_f;
    while (temp)
    {
        old_fd = cmd->output.fd;
        cmd->output.fd= open(temp->content, O_CREAT | O_RDWR | cmd->output.mode, 0644);
        if (!cmd->output.fd)
            return ;
        close_ancient_fd(old_fd);
        //you should exit properly and return Error
        ft_lstadd_back(&data.fds , ft_lstnew(&cmd->output.fd, INT));
        temp = temp ->next;
    }
}

void open_redir_files(t_cmd *cmd)
{
    t_list          *temp;
    int             old_fd;

    if (*data.status.exit_code)
        return ;
    temp = cmd->out_redirect_f;
    while (temp)
    {
        old_fd = cmd->output.fd;
        cmd->output.fd= open(temp->content, O_CREAT | O_RDWR | cmd->output.mode, 0644);
        if (!cmd->output.fd)
            return ;
        close_ancient_fd(old_fd);
        //you should exit properly and return Error
        ft_lstadd_back(&data.fds , ft_lstnew(&cmd->output.fd, INT));
        temp = temp ->next;
    }
    temp = cmd->in_redirect_f;
    if (data.input_piped)
        data.c++;
    while (temp)
    {
        old_fd = cmd->input.fd;
        if(ft_lst_contain(&cmd->heredoc_delimits, (char *)temp->content) && (data.c == 1 || data.c % 2 == 0 ))
        {
            ft_open_heredoc(cmd, (char *)temp->content);
        }
        else if (!ft_lst_contain(&cmd->heredoc_delimits, (char *)temp->content))
        {
            // printf ("-->|%s|\n", temp->content);
            cmd->input.fd= open(temp->content, O_RDONLY , 0644);
            if (!cmd->input.fd)
                return ;
            close_ancient_fd(old_fd);
            ft_lstadd_back(&data.fds , ft_lstnew(&cmd->input.fd ,INT));
            //mind the exit
        }
        temp = temp -> next;
    }
    // open_redir_files_in(cmd);
    // open_redir_files_ou(cmd);
}