/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 22:23:36 by samajat           #+#    #+#             */
/*   Updated: 2022/05/16 22:23:57 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    get_cmd_out_redirct(t_cmd *cmd, t_list *temp)
{
    char    *redir_str;

    redir_str = ft_strdup((char *)temp->next->content);
    ft_lstadd_back(&cmd->out_redirect_f, ft_lstnew(redir_str, CHAR));
    if (ft_strlen(((char *)temp->content)) == 1)
        cmd->output.mode = O_TRUNC;
    else
        cmd->output.mode = O_APPEND;
}

void    get_cmd_in_redirct(t_cmd *cmd, t_list *temp)
{
    char    *redir_str;

    redir_str = ft_strdup((char *)temp->next->content);
    ft_lstadd_back(&cmd->in_redirect_f, ft_lstnew(redir_str, CHAR));
    if (ft_strlen(((char *)temp->content)) == 1)
        cmd->input.mode = NINPUT;
    else
    {
        redir_str = ft_strdup((char *)temp->next->content);
        cmd->input.mode = HEREDOC;
        ft_lstadd_back(&cmd->heredoc_delimits, ft_lstnew(redir_str, CHAR));
    }
}

void    get_cmd_redirect (t_cmd *cmd, t_list *temp)
{
    if (((char *)temp->content)[0] == '>')
        get_cmd_out_redirct(cmd, temp);
    else if (((char *)temp->content)[0] == '<')
        get_cmd_in_redirct(cmd, temp);
}
