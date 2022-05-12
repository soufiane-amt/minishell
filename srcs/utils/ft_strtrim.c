/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 11:27:01 by samajat           #+#    #+#             */
/*   Updated: 2022/03/31 23:40:23 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	istrim(char c, char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (c == *(str + i))
			return (1);
		i++;
	}
	return (0);
}

static int	lastind(char *str, char *set)
{
	int	i;

	i = ft_strlen (str) - 1;
	while (str && i >= 0 && str[i])
	{
		if (!istrim(str[i], set))
			return (i);
		i--;
	}
	return (-1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*f_set;
	char	*f_s1;
	size_t	len;

	if (!s1)
		return (0);
	f_s1 = (char *)s1;
	f_set = (char *)set;
	while (istrim(*f_s1, (char *)set))
		f_s1++;
	if (!f_s1[0])
		return (ft_substr("", 0, 1));
	if (lastind(f_s1, f_set) == -1)
		return (ft_substr(f_s1, 0, ft_strlen(f_s1) + 1));
	len = (size_t)(lastind(f_s1, f_set));
	return (ft_substr(f_s1, 0, len + 1));
}
// #include <stdio.h>
// #include <string.h>
// int main ()
// {
// 	char *a = ft_strtrim("abcdba", "acb");
// 	printf ("%s", a);
// 	//  int i = strcmp(s, "d");
// 	//  printf("\n%d", i);
// }
