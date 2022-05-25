/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 15:02:55 by samajat           #+#    #+#             */
/*   Updated: 2022/05/25 20:03:42 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	new_oldpwd()
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
				e->value =NULL;
			}
			e->value = ft_strdup(get_env("PWD"));
			break ;
		}
		e = e->next;
	}
}

void	set_newpwd()
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

void	ft_cd(t_cmd *cmd)
{
	char	*path;
	t_list	*arg;

	arg = cmd->args;
	if (!arg)
    {
		new_oldpwd();
        chdir(get_env("HOME"));
        set_newpwd();
    }
	else if (((char *)arg->content)[0] == '~')
	{
		path = ft_strjoin(getenv("HOME"), st(arg->content));
		new_oldpwd();
		if (chdir(path))
			printf("minishell: cd: %s: %s\n", path, strerror(2));
        set_newpwd();
		free (path);
	}
	else if (!chdir(arg->content))
        set_newpwd();
    else if (chdir(arg->content) == -1)
		printf("minishell: cd: %s: %s\n", arg->content, strerror(2));
}
