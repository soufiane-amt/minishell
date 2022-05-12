/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 20:10:35 by samajat           #+#    #+#             */
/*   Updated: 2022/04/21 15:34:55 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


int main (int argc, char **argv, char **env)
{
    // t_token **token;

    // token = init_token();
    (void)argc;
    (void)argv;
    (void)env;
    open_prompt(env);
}