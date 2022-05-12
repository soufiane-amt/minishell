/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 19:41:59 by samajat           #+#    #+#             */
/*   Updated: 2022/04/25 00:25:32 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    free_arr(void **arr)
{
    int     i;

    if (!arr)
        return ;
    i = -1;
    while (arr[++i])
        free(arr[i]);
    if (arr)
        free(arr);
}