/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 23:00:34 by samajat           #+#    #+#             */
/*   Updated: 2022/05/12 23:00:35 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*temp;
	int		i;

	temp = lst;
	i = 0;
	while (temp != NULL && ++i)
		temp = temp -> next;
	return (i);
}

int	ft_token_size(t_token *token)
{
	t_token	*temp;
	int		i;

	temp = token;
	i = 0;
	while (temp != NULL && ++i)
		temp = temp -> next;
	return (i);
}

int	ft_env_size(t_env *lst)
{
	t_env	*temp;
	int		i;

	temp = lst;
	i = 0;
	while (temp != NULL && ++i)
		temp = temp -> next;
	return (i);
}
