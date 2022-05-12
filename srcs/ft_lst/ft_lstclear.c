/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 23:00:12 by samajat           #+#    #+#             */
/*   Updated: 2022/05/12 23:00:13 by samajat          ###   ########.fr       */
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

void	ft_env_clear(t_env **lst)
{
	t_env	*current;
	t_env	*next;

	current = *lst;
	while (current)
	{
		next = current->next;
		free (current);
		current = next;
	}
	free (lst);
	*lst = NULL;
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
