/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 23:00:49 by samajat           #+#    #+#             */
/*   Updated: 2022/05/15 19:18:42 by samajat          ###   ########.fr       */
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
    // t_token **token;

    // token = init_token();
    (void)argc;
    (void)argv;
    
    // puts("****\n");
    // show(env);
    // puts("****\n");
    open_prompt(env);
}