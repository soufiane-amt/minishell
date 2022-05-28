/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace_values.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelmoham <eelmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 20:34:51 by samajat           #+#    #+#             */
/*   Updated: 2022/05/29 00:18:07 by eelmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_replace_with_acctual_values(t_cmd *cmd)
{
	t_list	*temp;
	void	*to_free;

	temp = cmd->ex_elements;
	if (ft_is_redi_str(ft_lstlast(temp)->content))
	{
		chstatus (SYNTAX_ERROR, "'newline'", 258);
		return ;
	}
	while (temp)
	{
		to_free = temp->content;
		temp->content = _char(temp->content);
		if ((*g_data.status.exit_code))
		{
			free(to_free);
			return ;
		}
		free(to_free);
		temp = temp->next;
	}
}
