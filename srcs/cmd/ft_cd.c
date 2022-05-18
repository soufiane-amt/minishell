/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelmoham <eelmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 15:02:55 by samajat           #+#    #+#             */
/*   Updated: 2022/05/18 14:33:15 by eelmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	new_oldpwd(char *str)
{
	t_env	*e;

	e = data.enver;
	while (e)
	{
		if (!ft_strcmp(e->variable, "OLDPWD"))
		{
			e->value = ft_strdup(str);
			break ;
		}
		e = e->next;
	}
}

char	*st(char *str)
{
	return (str + 1);
}

void	set_oldpwd(void)
{
	t_env	*e;

	e = data.enver;
	while (e)
	{
		if (!ft_strcmp(e->variable, "PWD"))
		{
			new_oldpwd(e->value);
			break ;
		}
		e = e->next;
	}
}

void	ft_cd(t_cmd *cmd)
{
	char	*path;
	t_list	*arg;

	arg = cmd->args;
	set_oldpwd();
	if (!arg)
		chdir(get_env("HOME"));
	else if (((char *)arg->content)[0] == '~' || !arg->content)
	{
		path = ft_strjoin(getenv("HOME"), st(arg->content));
		if (chdir(path))
			printf("minishell: cd: %s: %s\n", path, strerror(2));
		free (path);
	}
	else if (chdir(arg->content))
		printf("minishell: cd: %s: %s\n", arg->content, strerror(2));
}
