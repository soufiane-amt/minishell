/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 19:07:02 by eelmoham          #+#    #+#             */
/*   Updated: 2022/05/16 20:49:41 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//Use a global variable to resolve the heredoc case
void     get_cmd(t_cmd *cmd)
{
    cmd->cmd = ft_strdup(_char((char *)cmd->ex_elements->content));
    if (!cmd->cmd)
        chstatus(MEMORY_LACK, NULL, 30);
    //command : should be freed
}
//1)You should take care later of the command looking like this : "ls" consider strtrim



//Same rule on comment (1) applies on options 
//overwrite white spaces
void    get_cmd_redirects(t_cmd *cmd)
{
    t_list  *temp;
    char    *redir_str;

    temp = cmd->ex_elements;
    while (temp && temp->next)
    {
        if (((char *)temp->content)[0] == '>')
        {
            redir_str = ft_strdup((char *)temp->next->content);
            ft_lstadd_back(&cmd->out_redirect_f, ft_lstnew(redir_str, CHAR));
            if (ft_strlen(((char *)temp->content)) == 1)
                cmd->output.mode = O_TRUNC;
            else
                cmd->output.mode = O_APPEND;
        }
        else if (((char *)temp->content)[0] == '<')
        {
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
            //Heredoc up
        }
        temp = temp ->next;
    }
}
//ls text>>output<note.txt>out arg>lol arg2 "-al" "new arg"
//Mode quote mode redirection // add_redirections
// space cannot be added unless we have Quote mode
void     get_cmd_args(t_cmd *cmd)
{
    t_list  *temp;
    char    *arg;

    temp = cmd->ex_elements->next;
    while (temp)
    {
        if(!ft_is_redi((((char *)temp ->content)[0])))
        {
            arg = ft_strdup(_char((char *)temp->content));
            if (!arg)
            {
                chstatus(MEMORY_LACK, NULL, 30);
                return ;
            }
            if (!ft_lst_contain (&cmd->in_redirect_f, arg) && !ft_lst_contain (&cmd->out_redirect_f, arg))
                ft_lstadd_back(&cmd->args, ft_lstnew(arg, CHAR));
            else
                free(arg);
        }
        temp = temp ->next;
    }
}

//echo hello> output>>outfile>result | cat <note.txt>out >>output
//Same rule on comment (1) applies on args 
//2)Protection is required , Not all the data will be available
t_cmd     *get_cmd_data (char  *command)
{
    t_cmd   *cmd;
    char    *t_command;

    cmd = ft_init_cmd ();
    if (!cmd)
        return(cmd);
    command = if_prenthesized(command, &t_command);
    check_prenthesis(command);
    check_syntax(cmd, command);
    if (*data.status.exit_code)
    {
        if ((t_command))
            free(t_command);
        return (cmd);
    }
    get_cmd(cmd);
    get_cmd_redirects(cmd);
    get_cmd_args(cmd);
    build_cmd (cmd);
    if (ft_strcmp("", cmd->cmd_str))
    {
        cmd ->f_cmd = ft_split (cmd->cmd_str, ' ');
        if (!cmd ->f_cmd)
        {
            chstatus(MEMORY_LACK, NULL, 30);
            if ((t_command))
                    free(t_command);
            return (NULL); 
        }
    }
    add_path(cmd);
    if ((t_command))
        free(t_command);
    return (cmd);
}
//I will create a function later that cleans the cmd from double quotes or even other
//stuff

//NOTE: Parsing will be avoided if the syntax of the command line is wrong or 
//in case of error
//what if you got double |