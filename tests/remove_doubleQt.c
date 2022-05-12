#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "../includes/minishell.h"

int ft_strlen(const char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);    
}

char *rmv_double_qt(char *str)
{
    char *var;
    int i;
    int j;

    i = 0;
    j = 0;
    if (str[0] == '"' && str[ft_strlen(str) - 1] == '"')
    {
        var = malloc (ft_strlen(str));
        while (str[i])
        {
            if (str[i] == '"')
                i++;
            else
            {
                var[j] = str[i];
                i++;
                j++;
            }
        }  
    }
    return (var);
}


int main()
{
    char me[] = "mehdi";
    me[0] = '"';
    me[4] = '"';

    printf("%s\n", rmv_double_qt(me));
}