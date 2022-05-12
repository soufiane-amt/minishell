/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 23:00:49 by samajat           #+#    #+#             */
/*   Updated: 2022/05/12 23:00:50 by samajat          ###   ########.fr       */
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