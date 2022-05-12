
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
        {
            chstatus(MEMORY_LACK, NULL, 30);
            return (NULL);
        }
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