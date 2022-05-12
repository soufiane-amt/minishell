/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 03:53:07 by samajat           #+#    #+#             */
/*   Updated: 2022/03/29 13:21:48 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new -> next = (*lst);
	(*lst) = new;
}

void	ft_token_add_front(t_token **lst, t_token *new)
{
	new -> next = (*lst);
	(*lst) = new;
}
