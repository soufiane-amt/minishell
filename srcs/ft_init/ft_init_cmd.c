/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 23:40:43 by samajat           #+#    #+#             */
/*   Updated: 2022/05/24 19:43:17 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*ft_init_cmd(void)
{
	t_cmd	*cmd;

	cmd = malloc (sizeof(t_cmd));
	if (!cmd)
	{
		chstatus(MEMORY_LACK, NULL, 30);
		return (NULL);
	}
	cmd ->cmd = NULL;
	cmd ->args = NULL;
	cmd ->in_redirect_f = NULL;
	cmd->out_redirect_f = NULL;
	cmd ->ex_elements = NULL;
	cmd ->heredoc_delimits = NULL;
	cmd ->cmd_str = NULL;
	cmd ->f_cmd = NULL;
	data.e = 0;
	cmd->input.mode = 0;
	cmd->output.mode = 0;
	cmd->input.fd = STDIN_FILENO;
	cmd->output.fd = STDOUT_FILENO;
	return (cmd);
}
