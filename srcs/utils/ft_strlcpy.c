/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 10:49:19 by samajat           #+#    #+#             */
/*   Updated: 2022/04/04 22:15:15 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	int		size;

	i = -1;
	size = 0;
	while (*(src + size))
		size++;
	if (!dstsize)
		return (size);
	while (++i < dstsize - 1 && *(src + i))
			*(dst + i) = *(src + i);
	*(dst + i) = 0;
	return (size);
}
/*
#include <stdio.h>
int main ()
{
	char dest[8];
	char scr[]="ABCDEFGHIJ";

	int i = ft_strlcpy(dest , scr , 5);
	printf("Return :%d ---Result :%s",i,dest);
}*/
