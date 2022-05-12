/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 21:41:33 by samajat           #+#    #+#             */
/*   Updated: 2022/03/31 19:27:10 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	temp = ft_lstlast(*lst);
	if (temp)
		temp -> next = new;
	else if (temp == NULL)
		*lst = new;
}

void	ft_token_add_back(t_token **token, t_token *new)
{
	t_token	*temp;

	temp = ft_tokenlast(*token);
	if (temp)
		temp -> next = new;
	else if (temp == NULL)
		*token = new;
}
