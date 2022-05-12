/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelmoham <eelmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 03:40:44 by samajat           #+#    #+#             */
/*   Updated: 2022/04/06 22:38:34 by eelmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*first_list;

	first_list = (t_list *)malloc(sizeof(t_list));
	if (first_list == NULL)
		return (NULL);
	first_list->content = content;
	first_list->next = NULL;
	return (first_list);
}

t_token	*ft_token_new(t_spliter *t_sep)
{
	t_token	*node;

	node = (t_token *) malloc (sizeof(t_token));
	if (!node)
		exit (1);
	node -> sep = t_sep;
	node -> next = NULL;
	return (node);
}

t_env	*ft_env_new(char *var, char *val)
{
	t_env	*first_list;
	first_list = (t_env *)malloc(sizeof(t_env));
	if (first_list == NULL)
		return (NULL);
	first_list->variable = var;
	first_list->value = val;
	first_list->next = NULL;
	return (first_list);
}
