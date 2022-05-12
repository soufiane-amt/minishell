/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 03:40:44 by samajat           #+#    #+#             */
/*   Updated: 2022/04/25 02:02:39 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"

t_list	*ft_lstnew(void *content, int   type)
{
	t_list	*node;

	node = (struct s_list *) malloc (sizeof(struct s_list));
	if (!node)
    {
        chstatus(MEMORY_LACK, NULL, 30);
        return (NULL);
    }
    if (type == INT)
	    node -> content = (int *)content;
    else
	    node -> content = (char *)content;
	node -> next = NULL;
	return (node);
}

t_token	*ft_token_new(t_spliter *t_sep)
{
	t_token	*node;

	node = (t_token *) malloc (sizeof(t_token));
	if (!node)
    {
        chstatus(MEMORY_LACK, NULL, 30);
        return (NULL);
    }
	node -> sep = t_sep;
	node -> next = NULL;
	return (node);
}
