/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 11:32:35 by samajat           #+#    #+#             */
/*   Updated: 2022/04/25 02:03:30 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		s1_s;
	int		s2_s;

	i = 0;
	s1_s = ft_strlen(s1);
	s2_s = ft_strlen(s2);
	str = (char *) malloc (sizeof(char) * (s1_s + s2_s + 1));
	if (!str)
    {
        chstatus(MEMORY_LACK, NULL, 30);
        return (NULL);
    }
	ft_strlcpy(str, s1, s1_s + 1);
	while (i < s2_s)
	{
		str[s1_s] = (char)s2[i];
		s1_s++;
		i++;
	}
	str[s1_s] = 0;
	return (str);
}
/*
#include <stdio.h>
#include <string.h>
int main ()
{
	printf("%s\n", ft_strjoin("Soufiane", " Amajat"));
}
*/
