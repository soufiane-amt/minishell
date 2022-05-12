/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 21:53:20 by samajat           #+#    #+#             */
/*   Updated: 2022/04/25 02:01:48 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	int		i;

	i = -1;
	if (!s1)
		return (NULL);
	str = (char *) malloc (sizeof(char) * (ft_strlen(s1) + 1));
	if (!str)
    {
        chstatus (MEMORY_LACK, NULL, 30);
		return (NULL);
    }
	while (s1[++i])
		str[i] = s1[i];
	str[i] = 0;
	return (str);
}
