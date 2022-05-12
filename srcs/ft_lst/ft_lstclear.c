/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 00:56:57 by samajat           #+#    #+#             */
/*   Updated: 2022/04/23 21:34:00 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


void	ft_lstclear(t_list **lst, int   free_content)
{
	t_list *tmp;

	if (lst)
	{
		while (*lst)
		{
			tmp = (*lst)->next;
			ft_lstdelone(lst, free_content);
			(*lst) = tmp;
		}
	}
}

// void	ft_tokenclear(t_token **token, int   free_content)
// {
// 	t_token *tmp;

// 	if (token)
// 	{
// 		while (*token)
// 		{
// 			tmp = (*token)->next;
// 			ft_tokendelone(token, free_content);
// 			(*token) = tmp;
// 		}
// 	}
// }