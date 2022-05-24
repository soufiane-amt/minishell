/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_extractor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 19:53:28 by samajat           #+#    #+#             */
/*   Updated: 2022/05/24 19:53:35 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minishell.h"

void	ft_extract_data(t_cmd *cmd, char *command)
{
	int	a;

	if (extract_norm(cmd, command, &data.e))
		a = 0;
	else if (extract_redir(cmd, command, &data.e))
		a = 0;
	else if (extract_quote(cmd, command, &data.e))
		a = 0;
	if ((command + data.e) && command[data.e])
	{
		ft_extract_data(cmd, command);
		if ((*data.status.exit_code))
			return ;
	}
	else
		ft_replace_with_acctual_values(cmd);
}
