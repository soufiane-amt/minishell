/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_herdoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 21:53:22 by samajat           #+#    #+#             */
/*   Updated: 2022/05/24 19:41:41 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_open_prompt(int fd, t_cmd *cmd, char *delimiter)
{
	char	*str;
	char	*f_str;

	str = ft_strdup("");
	f_str = ft_strdup("");
	if (!str || !f_str)
	{
		chstatus (MEMORY_LACK, NULL, 30);
		return ;
	}
	while (str && ft_strcmp(str, delimiter))
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
}

void	ft_open_heredoc(t_cmd *cmd, char *delimiter)
{
	int	fd;

	fd = open(".temp", O_CREAT | O_RDWR | O_TRUNC, 0777);
	if (fd < 0)
	{
		chstatus(FD_ERROR, NULL, 55);
		return ;
	}
	ft_open_prompt(fd, cmd, delimiter);
	cmd->input.fd = open(".temp", O_RDWR, 0777);
}
