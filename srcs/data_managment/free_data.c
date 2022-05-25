/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_g_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 15:56:43 by samajat           #+#    #+#             */
/*   Updated: 2022/05/25 01:42:38 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_t_data(void)
{
	unlink(".temp");
	if (g_data.input)
		free(g_data.input);
	if (g_data.all_paths)
		free_arr((void **) g_data.all_paths);
	if (g_data.status.status)
		free (g_data.status.status);
	if (g_data.status.exit_code)
		free (g_data.status.exit_code);
	if (g_data.fds)
		ft_lstclear (&g_data.fds, 0);
}

void	free_cmd(t_cmd *cmd)
{
	if (!cmd)
		return ;
	if (cmd->cmd)
		free(cmd->cmd);
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
		free (cmd->cmd_str);
	if (cmd->f_cmd)
		free_arr((void **)cmd->f_cmd);
	if (cmd)
	{
		free(cmd);
		cmd = NULL;
	}
}

void	free_spliter(t_spliter *spliter, int last_token)
{
	if (spliter ->prev_cmd)
		free_cmd(spliter ->prev_cmd);
	if (last_token && spliter->next_cmd)
		free_cmd(spliter->next_cmd);
	free(spliter);
	spliter = NULL;
}

void	free_enver(void)
{
	t_env	*temp;
	t_env	*temp2;

	temp = g_data.enver;
	while (temp)
	{
		temp2 = temp->next;
		free(temp->variable);
		free(temp->value);
		temp = temp2;
	}
}

void	free_tokens(t_token **token)
{
	t_token	*temp;
	int		last_element;
	t_token	*to_free;

	last_element = 0;
	temp = *token;
	while (temp)
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
