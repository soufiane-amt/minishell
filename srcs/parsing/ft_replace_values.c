/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace_values.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 20:34:51 by samajat           #+#    #+#             */
/*   Updated: 2022/05/16 22:40:01 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    ft_replace_with_acctual_values(t_cmd *cmd)
{
    t_list  *temp;
    void    *to_free;

    temp = cmd->ex_elements;
    while (temp)
    {
        to_free = temp->content;
        temp->content = _char(temp->content);
        free(to_free);
        temp = temp->next;
    }
}