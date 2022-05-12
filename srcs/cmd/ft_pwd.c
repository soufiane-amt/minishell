/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelmoham <eelmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 15:03:53 by samajat           #+#    #+#             */
/*   Updated: 2022/04/06 19:48:32 by eelmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char *set_pwd(t_data *data, char *new_path)
{
    t_env *e;

    e = data->enver;
    while (e)
    {
        if (!ft_strcmp(e->variable, "PWD"))
		{
			e->value = ft_strdup(new_path);
			break ;
		}
        e = e->next;
    }
	return (e->value);
}

char *ft_pwd(t_data *data)
{
		char cwd[PATH_MAX];
		
		if (getcwd(cwd, sizeof(cwd)) == NULL)
			perror ("can't get current path\n");
		else
			return (set_pwd(data, cwd));
		return (set_pwd(data, cwd));
}