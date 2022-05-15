/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 15:02:55 by samajat           #+#    #+#             */
/*   Updated: 2022/05/15 20:43:49 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void new_oldpwd(char *str)
{
	t_env *e;

	e = data.enver;
	while (e)
	{
		if (!ft_strcmp(e->variable, "OLDPWD"))
		{
			e->value = ft_strdup(str); // free
			break ;
		}
		e = e->next;
	}
}

char *st(char *str)
{
	return (str + 1);
}

void    ft_cd(t_cmd *cmd)
{
	char *path;
	t_env *e;
	t_list *arg;

	e = data.enver;
	arg = cmd->args;
	while (e)
	{
		if (!ft_strcmp(e->variable, "PWD"))
		{
			new_oldpwd(e->value);
			break ;
		}
		e = e->next;
	}
	if (!arg)
		chdir("/Users/samajat");
	else if (((char *)arg->content)[0] == '~' || !arg->content)
	{
		path = ft_strjoin(getenv("HOME"), st(arg->content));
		if (chdir(path))
			printf("bash: cd: %s: %s\n", path, strerror(2));
		free (path);
	}
	else if (chdir(arg->content))
		printf("bash: cd: %s: %s\n", arg->content, strerror(2));
}