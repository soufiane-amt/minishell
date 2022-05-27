/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelmoham <eelmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 23:00:19 by samajat           #+#    #+#             */
/*   Updated: 2022/05/27 01:35:17 by eelmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_lstdelone(t_list **lst, int free_content)
{
	if (!lst || !(*lst)->content)
		return ;
	if (free_content)
		free((*lst)->content);
	(*lst)->content = NULL;
	free (*lst);
	lst = NULL;
}
