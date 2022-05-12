/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelmoham <eelmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 03:34:57 by samajat           #+#    #+#             */
/*   Updated: 2022/03/28 22:27:40 by eelmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*current;

	if (!f || !lst)
		return ;
	current = lst;
	while (current != NULL)
	{
		current = current -> next;
	}
}

void	ft_token_iter(t_token *lst, void (*f)(void *))
{
	t_token	*current;

	if (!f || !lst)
		return ;
	current = lst;
	while (current != NULL)
	{
		current = current -> next;
	}
}
