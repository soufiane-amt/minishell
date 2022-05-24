/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 15:02:55 by samajat           #+#    #+#             */
/*   Updated: 2022/05/24 01:11:12 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	new_oldpwd(char *str)
{
	t_env	*e;
    char    *forfree;

	e = data.enver;
	while (e)
	{
		if (!ft_strcmp(e->variable, "OLDPWD"))
		{
            forfree = e->value;
			e->value = ft_strdup(str);
            free(forfree);
			break ;
		}
		e = e->next;
	}
}

char    *set_newpwd(char *new_path)
{
	t_env	*e;
    char    *forfree;

	e = data.enver;
	while (e)
	{
		if (!ft_strcmp(e->variable, "PWD"))
		{
            forfree = e->value;
            new_oldpwd(forfree);
			e->value = new_path;
            free(forfree);
			break ;
		}
		e = e->next;
	}
    return (e->value);
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
	// new_newpwd();
	if (!arg)
    {
        chdir(get_env("HOME"));
        set_newpwd(ft_pwd());
    }
	else if (((char *)arg->content)[0] == '~')
	{
		path = ft_strjoin(getenv("HOME"), st(arg->content));
		if (chdir(path))
			printf("minishell: cd: %s: %s\n", path, strerror(2));
        set_newpwd(ft_pwd());
		free (path);
	}
	else if (!chdir(arg->content))
        set_newpwd(ft_pwd());
    else if (chdir(arg->content) == -1)
		printf("minishell: cd: %s: %s\n", arg->content, strerror(2));
}
