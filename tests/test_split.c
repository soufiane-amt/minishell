/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 22:16:39 by samajat           #+#    #+#             */
/*   Updated: 2022/03/26 22:28:04 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void    print_arr(char **arr)
{
    int i;

    i = 0;
    while (arr[i])
    {
        printf ("-->%s\n", arr[i]);
        i++;
    }
    
}

int main()
{
    char str[] = "hello  "" w""  rld";
    char    **arr;

    arr = ft_split(str, '"');
    print_arr(arr);
}