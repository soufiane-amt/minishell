/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_env_expo2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelmoham <eelmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 23:02:01 by samajat           #+#    #+#             */
/*   Updated: 2022/05/18 16:23:04 by eelmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	protect(char *s)
{
	if (!s)
	{
		chstatus(MEMORY_LACK, NULL, 30);
		return (1);
	}
	else
		return (0);
}

char	*env_var(char *str)
{
	int		j;
	int		i;
	char	*s;

	s = malloc((ft_strlen(str) - (count_c(str, '$') + count_c(str, '"'))) + 1);
	if (protect(&s) == 1)
		return (NULL);
	i = 0;
	j = 0;
	if (str[0] == '"' || str[0] == '$' || (str[0] == '"' && str[1] == '$'))
	{
		while (str[i])
		{
			if (str[i] == '$' || str[i] == '"')
				i++;
			else
			{
				s[j] = str[i];
				j++;
				i++;
			}
		}
	}
	s[j] = '\0';
	return (s);
}
