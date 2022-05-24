/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 20:50:03 by samajat           #+#    #+#             */
/*   Updated: 2022/05/24 19:08:46 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	notify_error(char *message, char *added)
{
	if (!added)
	{
		ft_putstr_fd(message, 2);
		ft_putstr_fd("\n", 2);
	}
	else
	{
		ft_putstr_fd(message, 2);
		ft_putstr_fd(added, 2);
		ft_putstr_fd("\n", 2);
	}
}

void	print_error_e(char *message)
{
	ft_putstr_fd(message, 2);
	exit(1);
}
