/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelmoham <eelmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 15:03:53 by samajat           #+#    #+#             */
/*   Updated: 2022/05/30 17:29:22 by eelmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*set_pwd(char *new_path)
{
	t_env	*e;

	e = g_data.enver;
	while (e)
	{
		if (!ft_strcmp(e->variable, "PWD"))
		{
			free(e->value);
			e->value = ft_strdup(new_path);
			free(new_path);
			break ;
		}
		e = e->next;
	}
	return (new_path);
}

char	*ft_pwd(void)
{
	char	*cwd;

	cwd = NULL;
	cwd = getcwd(cwd, PATH_MAX);
	if (!cwd)
	{
		chstatus(OTHER_ERR, NULL, 1);
		return (NULL);
	}
	return (set_pwd(cwd));
}
