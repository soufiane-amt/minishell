/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_void.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 19:49:02 by eelmoham          #+#    #+#             */
/*   Updated: 2022/04/24 23:39:12 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int ft_strlen(const char  *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);    
}

char	*ft_strdup(const char *s1)
{
	char	*str;
	int		i;

	i = -1;
	if (!s1)
		return (NULL);
	str = (char *) malloc (sizeof(char) * (ft_strlen(s1) + 1));
	if (!str)
		return (NULL);
	while (s1[++i])
		str[i] = s1[i];
	str[i] = 0;
	return (str);
}

int main()
{
    void    *str;

    str = ft_strdup("soufiane");
    printf ("a = %s\n", (char *)str);
    free(str);
    str = NULL;
    printf ("a = %s\n", (char *)str);
}