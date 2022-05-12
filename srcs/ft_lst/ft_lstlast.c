/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 18:21:49 by samajat           #+#    #+#             */
/*   Updated: 2022/03/31 20:50:39 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*temp;

	temp = lst;
	if (temp != NULL)
		while (temp->next)
			temp = temp->next;
	return (temp);
}

t_token	*ft_tokenlast(t_token *token)
{
	t_token	*temp;

	temp = token;
	if (temp != NULL)
		while (temp->next)
			temp = temp->next;
	return (temp);
}
