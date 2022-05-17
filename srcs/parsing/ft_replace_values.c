/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace_values.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelmoham <eelmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 20:34:51 by samajat           #+#    #+#             */
/*   Updated: 2022/05/17 13:41:06 by eelmoham         ###   ########.fr       */
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