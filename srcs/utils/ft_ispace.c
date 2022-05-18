/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ispace.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelmoham <eelmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 22:06:08 by samajat           #+#    #+#             */
/*   Updated: 2022/05/18 15:01:01 by eelmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_ispace(char c)
{
	if (!c)
		return (0);
	if (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

int	ft_override_spaces(char *s, int *i)
{
	if (!s)
		return (0);
	while (s[*i] && ft_ispace(s[*i]))
		(*i)++;
	return (1);
}
