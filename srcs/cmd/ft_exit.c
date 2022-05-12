/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelmoham <eelmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 16:20:51 by eelmoham          #+#    #+#             */
/*   Updated: 2022/04/09 16:27:45 by eelmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void ft_exit(t_cmd *cmd, t_data *data)
{
    ft_lstclear(cmd->args);
    ft_lstclear(cmd->options);
    ft_lstclear(cmd->in_redirect_f);
    ft_lstclear(cmd->out_redirect_f);
    ft_env_clear(data->enver);
    exit(1);   
}