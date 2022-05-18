/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelmoham <eelmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 00:00:43 by samajat           #+#    #+#             */
/*   Updated: 2022/05/18 14:52:35 by eelmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	add_string(char **str, char	*added)
{
	char	*t_str;

	t_str = *str;
	*str = ft_strjoin(*str, added);
	free (t_str);
	free(added);
}
