/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   man.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelmoham <eelmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 17:40:28 by eelmoham          #+#    #+#             */
/*   Updated: 2022/04/05 22:11:06 by eelmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
int main (int argc, char **argv, char **env)
{
    t_data data;
    // t_token **token;

    // token = init_token();
    (void)argc;
    (void)argv;
    open_prompt(&data ,env);
    
}