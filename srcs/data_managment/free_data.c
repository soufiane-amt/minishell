/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 15:56:43 by samajat           #+#    #+#             */
/*   Updated: 2022/05/16 21:20:42 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//echo hello >text | echo hello | ls -al | wc -l
void    free_t_data()
{
    unlink (".temp");
    if (data.input)
        free(data.input);
    if (data.all_paths)
        free_arr((void **) data.all_paths);
    if (*data.status.exit_code)
        free (data.status.exit_code);
    if (data.status.status)
        free (data.status.status);
    if (data.fds)
        ft_lstclear (&data.fds, 0);
}

void    free_cmd (t_cmd *cmd)
{
    if (!cmd)
        return ;
    if (cmd->cmd)
    {
        free(cmd->cmd);
        cmd->cmd = NULL;
    }
    if (ft_lstsize(cmd->args))
        ft_lstclear(&cmd->args, 1);
    if (ft_lstsize(cmd->in_redirect_f))
        ft_lstclear(&cmd->in_redirect_f, 1);
    if (ft_lstsize(cmd->out_redirect_f))
        ft_lstclear(&cmd->out_redirect_f, 1);
    if (cmd->ex_elements && ft_lstsize(cmd->ex_elements))
        ft_lstclear(&cmd->ex_elements, 1);
    if (ft_lstsize(cmd->heredoc_delimits))
        ft_lstclear(&cmd->heredoc_delimits, 1);
    if (cmd ->cmd_str)
    {
        free (cmd->cmd_str);
        cmd ->cmd_str = NULL;
    }
    if (cmd->f_cmd)
        free_arr((void **)cmd->f_cmd);
    if (cmd)
    {
        free(cmd);
        cmd = NULL;
    }
}

void    free_spliter (t_spliter *spliter, int   last_token)
{
    if (spliter ->Prevcmd)
        free_cmd (spliter ->Prevcmd);
    if (last_token && spliter->Nextcmd)
        free_cmd (spliter->Nextcmd);
    free(spliter);
    spliter = NULL;
}

void    free_tokens (t_token **token)
{
    t_token	*temp;
    int     last_element;
    t_token *to_free;

    if (*data.status.exit_code)
        return ;
    last_element = 0;
	temp = *token;
	while (temp )
	{
        to_free = temp;
        if (!temp->next)
            last_element = 1;  
        if (temp->sep)  
            free_spliter(temp->sep, last_element);
		temp = temp->next;
        free(to_free);
	}
    
    free (token);
    token = NULL;
}
