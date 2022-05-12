/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelete_last.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 12:05:38 by samajat           #+#    #+#             */
/*   Updated: 2022/03/29 13:32:55 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_lstdelete_last(t_list **lst)
{
	int		i;
	t_list	*last;
	t_list	*prelast;

	i = 0;
	if (!(*lst) || !(*lst)->next)
		return (0);
	prelast = *lst;
	while (i < ft_lstsize(*lst) - 2)
	{
		prelast = prelast -> next;
		i++;
	}
	last = prelast -> next;
	free (last);
	last = NULL;
	prelast -> next = NULL;
	return (1);
}

int	ft_tokendelete_last(t_token **token)
{
	int		i;
	t_token	*last;
	t_token	*prelast;

	i = 0;
	if (!(*token) || !(*token)->next)
		return (0);
	prelast = *token;
	while (i < ft_token_size(*token) - 2)
	{
		prelast = prelast -> next;
		i++;
	}
	last = prelast -> next;
	free (last);
	last = NULL;
	prelast -> next = NULL;
	return (1);
}

