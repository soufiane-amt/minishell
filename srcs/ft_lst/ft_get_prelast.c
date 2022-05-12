/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_prelast.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:22:54 by samajat           #+#    #+#             */
/*   Updated: 2022/03/30 19:56:16 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*ft_get_prelast(t_list **lst)
{
	t_list	*temp;

	temp = *lst;
	if (temp && temp -> next)
		while (temp->next->next)
			temp = temp->next;
	return (temp);
}

t_token	*ft_get_prelast(t_token **token)
{
	t_token	*temp;

	temp = *token;
	if (temp && temp -> next)
		while (temp->next->next)
			temp = temp->next;
	return (temp);
}