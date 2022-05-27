/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelmoham <eelmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 15:02:55 by samajat           #+#    #+#             */
/*   Updated: 2022/05/27 16:06:48 by eelmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	new_oldpwd(void)
{
	t_env	*e;

	e = g_data.enver;
	while (e)
	{
		if (!ft_strcmp(e->variable, "OLDPWD"))
		{
			if (e->value)
			{
				free(e->value);
				e->value = NULL;
			}
			e->value = ft_strdup(get_env("PWD"));
			break ;
		}
		e = e->next;
	}
}

void	set_newpwd(void)
{
	t_env	*e;

	e = g_data.enver;
	while (e)
	{
		if (!ft_strcmp(e->variable, "PWD"))
		{
			getcwd(e->value, PATH_MAX);
			break ;
		}
		e = e->next;
	}
}

char	*st(char *str)
{
	return (str + 1);
}

void	go_to(t_list *arg, char *str)
{
	char	*path;

	if (!arg)
	{
		chdir(get_env("HOME"));
		set_newpwd();
	}
	else if (!ft_strcmp((char *)arg->content, "-"))
	{
		chdir(str);
		free(str);
		set_newpwd();
	}
	else if (((char *)arg->content)[0] == '~')
	{
		path = ft_strjoin(getenv("HOME"), st(arg->content));
		if (chdir(path))
			printf("minishell: cd: %s: %s\n", path, strerror(2));
		set_newpwd();
		free (path);
	}
	else if (!chdir(arg->content))
		set_newpwd();
	else if (chdir(arg->content) == -1)
		chstatus(NO_F_OR_D, NULL, 1);
}

void	ft_cd(t_cmd *cmd)
{
	t_list	*arg;
	char	*str;

	arg = cmd->args;
	str = NULL;
	if (arg && !ft_strcmp((char *)arg->content, "-"))
		str = ft_strdup(get_env("OLDPWD"));
	new_oldpwd();
	go_to(arg, str);
}
