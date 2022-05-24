/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_contain.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 15:04:38 by samajat           #+#    #+#             */
/*   Updated: 2022/05/24 20:01:14 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_lst_contain(t_list **lst, char *str)
{
	t_list	*temp;

	temp = *lst;
	if (!str || !temp)
		return (0);
	while (temp)
	{
		if (!ft_strcmp(str, temp->content))
			return (1);
		temp = temp->next;
	}
	return (0);
}
