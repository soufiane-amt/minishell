
#include <stdio.h>
#include <stdlib.h>
#define MEMORY_LACK "the system has a lack of  memory, please\
        free up some space and try again!"

#define SYNTAX_ERROR "bash: syntax error near unexpected token"


char    *input ;

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
int ft_ispace (char c)
{
    if (c =='\t' || c =='\n' || c == '\v' ||
        c == '\f' || c == '\r' || c == ' ')
        return (1);
    return (0);
}

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

int     prethesis_are_parallel (char    *str)
{
    int i;
    int a;
    int b;
    int j;

    i = 0;
    a = 0;
    b = 0;
    j = ft_strlen (str) - 1;
    while (ft_ispace(str[i]))
        i++;
    while (str[i] == '(')
    {
        i++;
        a++;
    }
    while (ft_ispace(str[j]))
        j--;
    while (str[j] == ')')
    {
        j--;
        b++;
    }
    return (a - b);
}
void    check_input_prethesis (char **str)
{
    int     i;
    int     j;
    char    *to_free;

    i = 0;
    to_free = input;
    j = ft_strlen (input) - 1;
    while (input && ft_ispace(input[i]))
        i++;
    if (input[i] == '(')
    {
        while (input && ft_ispace(input[j]))
            j--;
        if (input[j] == ')')
        {
            input = ft_substr(input, i + 1, j - i - 1);
            if (!input)
            {
                puts (MEMORY_LACK);
                return ;
            }
            free (to_free);
        }
        else
        {
            puts(SYNTAX_ERROR);
            return ;
        }
    }
}

int main ()
{
    input = ft_strdup("((ls)))");
    check_input_prethesis ();
    printf ("%s\n", input);
}
