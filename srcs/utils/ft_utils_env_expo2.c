
#include "minishell.h"

char *rmv_double_qt(char *str)
{
    char *var;
    int i;
    int j;

    i = 0;
    j = 0;
    var = malloc (ft_strlen(str));
    if (str[0] == '"' && str[ft_strlen(str) - 1] == '"')
    {
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