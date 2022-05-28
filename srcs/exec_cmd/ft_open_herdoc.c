/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_herdoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelmoham <eelmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 21:53:22 by samajat           #+#    #+#             */
/*   Updated: 2022/05/29 00:02:21 by eelmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_open_prompt(int fd, t_cmd *cmd, char *delimiter)
{
	char	*str;
	// static	int	i;

	str = ft_strdup("");
	if (!str)
	{
		chstatus (MEMORY_LACK, NULL, 30);
		return ;
	}
	while (!g_data.exit_herdoc)
	{
		ft_putstr_fd(str, fd);
		free(str);
		str = readline("heredoc>");
		if (!str || !ft_strcmp(str, delimiter))
			break ;
		if(str[0])
			str = ft_charjoin(str, '\n');
		// if (i >= 1)
		// 	ft_putstr_fd("\n", fd);
		// i++;
	}
	// ft_putstr_fd("\n", fd);
	close(fd);
	if (cmd->input.fd != STDIN_FILENO)
		close (cmd->input.fd);
	free(str);
}

void	ft_open_heredoc(t_cmd *cmd, char *delimiter)
{
	int	fd;

	g_data.exit_herdoc = FALSE;
	fd = open(".temp", O_CREAT | O_RDWR | O_TRUNC, 0777);
	if (fd < 0)
	{
		chstatus(FD_ERROR, NULL, 55);
		return ;
	}
	ft_open_prompt(fd, cmd, delimiter);
	cmd->input.fd = open(".temp", O_RDWR, 0777);
}
