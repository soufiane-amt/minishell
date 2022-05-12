/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 18:13:20 by samajat           #+#    #+#             */
/*   Updated: 2022/04/18 18:39:51 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_lstprint(t_list *lst)
{
	t_list	*temp;

	temp = lst;
	while (temp)
	{
		printf("|%s|\n", temp->content);
		temp = temp->next;
	}
}

void	ft_cmd_print(t_cmd *cmd)
{
	printf("\ncmd = %s\nOptions: ", cmd->cmd);
    ft_lstprint(cmd->options);
    printf("\nargs : ");
    ft_lstprint(cmd->args);
    printf("\nredirected input : \n");
    ft_lstprint(cmd->in_redirect_f);
    printf("\nredirected output : \n|");
    ft_lstprint(cmd->out_redirect_f);
    printf ("|\ninput,FD = %d\nout,FD = %d\n",cmd->input.fd ,cmd->output.fd);
    printf ("\ninput.mode = %d\noutput.mode = %d\n------------\n",cmd->input.mode ,cmd->output.mode);
    printf ("cmd_str = %s\n", cmd->cmd_str);
}

void	ft_tokenprint(t_token **token)
{
	t_token	*temp;

	temp = *token;
	while (temp)
	{
        printf ("-----------------\n");
        ft_cmd_print(temp->sep->Prevcmd);
        printf("\n sep : %c\n------------\n", (*token)->sep->spec_char);
        ft_cmd_print(temp->sep->Nextcmd);
		temp = temp->next;
	}
}

