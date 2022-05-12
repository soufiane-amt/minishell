/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:06:25 by samajat           #+#    #+#             */
/*   Updated: 2022/03/31 21:16:17 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char    *ft_substr(char const *s, unsigned int start, size_t len)
{
        char    *substr;
        size_t  i;
        size_t  j;

        i = -1;
        j = 0;
        if (!s)
            return (NULL);
        if (len > (size_t)ft_strlen(s) + 1)
                len = ft_strlen(s);
        substr = (char *) malloc (sizeof(char) * (len + 1));
        if (!substr)
                return (NULL);
        while (s[++i])
        {
                if (i >= start && j < len)
                {
                        substr[j] = s[i];
                        j++;
                }
        }
        substr[j] = 0;
        return (substr);
}