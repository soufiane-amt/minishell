/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 23:00:49 by samajat           #+#    #+#             */
/*   Updated: 2022/05/16 22:02:39 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"
// void show(char **env)
// {
//     int i = 0;
//     while (env[i])
//     {
//         printf("%s\n", env[i]);
//         i++;
//     }
// }
int main (int argc, char **argv, char **env)
{
    (void)argc;
    (void)argv;
    
    open_prompt(env);
}