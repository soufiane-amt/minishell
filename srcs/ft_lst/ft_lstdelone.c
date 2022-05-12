/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelmoham <eelmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 22:35:43 by samajat           #+#    #+#             */
/*   Updated: 2022/05/11 17:16:54 by eelmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_lstdelone(t_list *lst)
{
	if (!lst)
		return ;
	free (lst);
	lst = NULL;
}

// void	ft_token_delone(t_token *lst)
// {
// 	if (!lst)
// 		return ;
// 	free (lst);
// 	lst = NULL;
// }
