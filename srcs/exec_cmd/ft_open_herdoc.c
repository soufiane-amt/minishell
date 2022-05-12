/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_herdoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 21:53:22 by samajat           #+#    #+#             */
/*   Updated: 2022/04/25 01:56:34 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    ft_open_heredoc (t_cmd *cmd, char   *delimter)
{
	char	*str;
	char	*f_str;
    int fd;

    fd = open(".temp", O_CREAT | O_RDWR | O_TRUNC , 0777);
    //mind the exit
    str = ft_strdup("");
    f_str = ft_strdup("");
    if (!str || !f_str)
        return ;
	while (str && ft_strcmp(str, delimter))
	{
		ft_putstr_fd("heredoc>", 1);
		ft_putstr_fd(f_str, fd);
		free(str);
		free(f_str);
        f_str = get_next_line(0);
		str = ft_substr(f_str, 0, ft_strlen(f_str) - 1);
	}
    close(fd);
    if (cmd->input.fd != STDIN_FILENO)
        close (cmd->input.fd);
	free(str);
	free(f_str);
    str = NULL;
    f_str = NULL;
    cmd->input.fd = open(".temp",  O_RDWR , 0777);
}