/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 19:28:28 by samajat           #+#    #+#             */
/*   Updated: 2022/05/22 21:46:07 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_get_token(t_token **token)
{
	t_spliter	*f_sep;

	if ((*data.status.exit_code) || !token)
		return ;
	f_sep = ft_split_by_sep(data);
	if ((*data.status.exit_code))
	{
		ft_token_add_back(token, ft_token_new(f_sep));
		return ;
	}
	while (f_sep)
	{
		ft_token_add_back(token, ft_token_new(f_sep));
		f_sep = ft_split_by_sep(data);
		if (!data.spliter_sucess)
		{
			ft_token_add_back(token, ft_token_new(f_sep));
			break ;
		}
	}
}
