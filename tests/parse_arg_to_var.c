#include "../includes/minishell.h"

int count_sp_char(char *st)
{
    int i;
    int count;

    i = 0;
    count  = 0;
    while (st[i])
    {
        if (st[i] == '\'' || st[i] == '\"' || st[i] == '$')
         count++;
        i++;
    }
    return (count);
}

char *parse_var(char *st)
{
    char *var;
    int i;
    int j;

    var = malloc(count_sp_char(st) + 1);
    i = 0;
    j = 0;
    while (st[i])
    {
        if (st[i] == '\'' || st[i] == '\"' || st[i] == '$')
            i++;
        else
        {
            var[j] = st[i];
            j++;
            i++;
        }
    }
    var[j] = '\0';
    return (var);
}

int main()
{
    char str[] = "\"\'$HOME\'\"";

    if (str[0] == '$')
        printf("var is :%s \n", getenv(parse_var(str)));
    else if ((str[0] == '\"' && str[strlen(str) - 1] == '\"') && (str[1] == '\'' && str[strlen(str) - 2] == '\''))
        printf("var is :\'%s\' \n", getenv(parse_var(str)));
    else if (str[0] == '\"' && str[strlen(str) - 1] == '\"')
        printf("var is :%s \n", getenv(parse_var(str)));
}