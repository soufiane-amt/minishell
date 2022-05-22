/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_user_input.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 18:56:03 by samajat           #+#    #+#             */
/*   Updated: 2022/05/22 21:46:07 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int check_user_input (char  *str)
{
    if ((*data.status.exit_code))
        return (0);
    if (!(str) || !ft_strcmp(str, ""))
        return (0);
    if (str[0] == '|' || str[ft_strlen(str) - 1] == '|')
    {
        chstatus(SYNTAX_ERROR, "|", 258);
        return (0);
    }
    return (1);
}