/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelmoham <eelmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 00:56:57 by samajat           #+#    #+#             */
/*   Updated: 2022/03/30 15:41:01 by eelmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*current;
	t_list	*next;

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

void	ft_token_clear(t_token **lst)
{
	t_token	*current;
	t_token	*next;

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