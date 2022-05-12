/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelete_top.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 17:54:55 by samajat           #+#    #+#             */
/*   Updated: 2022/03/29 13:34:09 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_lstdelete_top(t_list **lst)
{
	t_list	*temp;

	if (!*lst)
		return (0);
	temp = *lst;
	*lst = temp -> next;
	free (temp);
	temp = NULL;
	return (1);
}

int	ft_tokendelete_top(t_token **token)
{
	t_token	*temp;

	if (!*token)
		return (0);
	temp = *token;
	*token = temp -> next;
	free (temp);
	temp = NULL;
	return (1);
}
