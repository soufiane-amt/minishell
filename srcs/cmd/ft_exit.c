/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 16:20:51 by eelmoham          #+#    #+#             */
/*   Updated: 2022/05/14 18:26:00 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void ft_exit(t_cmd *cmd)
{
    (void)cmd;
    // ft_lstclear(cmd->args);
    // ft_lstclear(cmd->options);
    // ft_lstclear(cmd->in_redirect_f);
    // ft_lstclear(cmd->out_redirect_f);
    // ft_env_clear(data.enver);
    exit(1);   
}