/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_content.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelmoham <eelmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 21:25:34 by samajat           #+#    #+#             */
/*   Updated: 2022/05/18 14:53:59 by eelmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	display_file(int fd)
{
	char	*str;

	str = ft_strdup("");
	while (str)
	{
		fprintf(stderr, "%s\n", str);
		get_next_line(fd);
	}
	close(fd);
}
