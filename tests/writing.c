/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 20:05:39 by samajat           #+#    #+#             */
/*   Updated: 2022/04/15 20:20:42 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
# include <fcntl.h>

int ft_strlen(const char *str)
{
    int i;

    i = 0;
    if (!str)
        return (0);
    while (str[i])
        i++;
    return (i);    
}

void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}

int main ()
{
    int  fd;
    char    buffer[2];
    int     n;

    fd = open ("file.txt", O_CREAT| O_RDWR , 0777);
    ft_putstr_fd ("hello world\n", fd);
    n = 1;
    while (n)
    {
        n = read(fd, buffer, 2);
        printf ("%s", buffer);
    }
}