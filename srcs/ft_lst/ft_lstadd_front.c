/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 23:00:08 by samajat           #+#    #+#             */
/*   Updated: 2022/05/24 19:46:00 by samajat          ###   ########.fr       */
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
