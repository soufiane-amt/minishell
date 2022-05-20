/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelmoham <eelmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 15:03:53 by samajat           #+#    #+#             */
/*   Updated: 2022/05/20 14:08:59 by eelmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char *set_pwd(char *new_path)
{
    t_env *e;

    e = data.enver;
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

char *ft_pwd()
{
    char cwd[PATH_MAX];
    // printf("%s\n", getcwd(cwd, sizeof(cwd)));
    if (getcwd(cwd, sizeof(cwd)) == NULL)
    {
        perror ("can't get current path\n");
        return (NULL);
    }
    return (set_pwd(cwd));
}
