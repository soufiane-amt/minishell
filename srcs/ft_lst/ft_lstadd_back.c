/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelmoham <eelmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 21:41:33 by samajat           #+#    #+#             */
/*   Updated: 2022/03/30 19:52:11 by eelmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!new)
		return ;
	if (!(*lst))
		*lst = new;
	else
		ft_lstlast((*lst))->next = new;
}

void	ft_token_add_back(t_token **lst, t_token *new)
{
	if (!new)
		return ;
	if (!(*lst))
		*lst = new;
	else
		ft_tokenlast((*lst))->next = new;
}

void	ft_env_tadd_back(t_env **lst, t_env *new)
{
	if (!new)
		return ;
	if (!(*lst))
		*lst = new;
	else
		ft_env_last((*lst))->next = new;
}