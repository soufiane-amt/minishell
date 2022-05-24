/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_token.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 23:48:06 by samajat           #+#    #+#             */
/*   Updated: 2022/05/24 19:43:57 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	**init_token(void)
{
	t_token	**token;

	token = malloc (sizeof(t_token *));
	if (!token)
	{
		chstatus(MEMORY_LACK, NULL, 30);
		return (NULL);
	}
	*token = NULL;
	return (token);
}
