/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 17:19:19 by samajat           #+#    #+#             */
/*   Updated: 2022/05/15 21:20:59 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int     ft_is_quote (char   c)
{
    if (c == '\'' || c == '\"')
        return (1);
    return (0);
}

int     ft_is_redi (char   c)
{
    if (c == '>' || c == '<')
        return (1);
    return (0);
}

int     ft_is_redirection(char *str)
{
    if (!ft_strcmp(">>", str) || !ft_strcmp("<<", str) ||
        !ft_strcmp(">", str) || !ft_strcmp("<", str))
        return (1);
    return (0);
}
