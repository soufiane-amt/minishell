/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_extract.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 02:17:50 by samajat           #+#    #+#             */
/*   Updated: 2022/04/24 23:39:12 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
////ls text>>output<note.txt>out arg>lol arg2 "-al" "new arg"
//Mode quote mode redirection // add_redirections
// space cannot be added unless we have Quote mode
int ft_ispace (char c)
{
    if (c =='\t' || c =='\n' || c == '\v' ||
        c == '\f' || c == '\r' || c == ' ')
        return (1);
    return (0);
}

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
//-----------------------------------------------
int     ft_is_quote (char   c)
{
    if (c == '\'' || c == '\"')
        return (1);
    return (0);
}

int     ft_is_redi (char   c)
{
    if (c == '>' || c == '<')
        return (1);
    return (0);
}
    
int     is_delimter (char c, char *delimeter)
{
    int i;

    i = 0;
    while (delimeter[i])
    {
        if (c == delimeter[i])
            return (1);
        i++;
    }
    return (0);
}

char    *extract_norm(char  *str, int   *i)
{
    char    *s;
    int     start;

    start = *i;
    if (!str || !str[*i])
        return (NULL);
    if (ft_is_quote(str[*i]) || ft_is_redi(str[*i]))
        return (NULL);
    while (str[*i] && !is_delimter(str[*i], " <>"))
        (*i)++;
    s = ft_substr(str, start, *i - start);
    while (ft_ispace(str[*i]))
        (*i)++;
    printf ("%s", s);
    return (s);
}

//you should handle the quote type are not the same reflex

//Quote keeper && quote ridder
char    *extract_quote(char  *str, int   *i)
{
    // int quoting_type;
    int start;
    char    *s;

    start = *i;
    while (str[*i] && (str[*i] == '\'' || str[*i] == '\"'))
        (*i)++;
    while (str[*i] && str[*i] != '\'' && str[*i] != '\"')
        (*i)++;
    while (str[*i] && (str[*i] == '\'' || str[*i] == '\"'))
        (*i)++;
    s = ft_substr(str, start, *i - start);
    (*i)++;
    printf ("%s", s);
    return (s);
}

char    *extract_redir(char *str, int *i)
{
    char    *s;

    if((str[*i] == '>' && str[(*i) + 1] == '>') || (str[*i] == '<' && str[(*i) + 1] == '<'))
    {
        s = ft_substr(str, *i, 2);
        (*i)+=2;
        printf ("%s", s);
        return (s);
    }
    else if(str[*i] == '>'|| str[*i] == '<')
    {
        s = ft_substr(str, *i, 1);
        (*i)++;
        printf ("%s", s);
        return (s);
    }
    return (NULL);
}


void    extract (char   *str)
{
    static int  i;

    if (!(str + i) && !str[i])
        return ;
    if (extract_norm(str, &i))
        printf ("\n");
    else if (extract_redir(str, &i))
        printf ("\n");
    else if (extract_quote(str, &i))
        printf ("\n");
    if (str[i])
        extract(str);
}

int main ()
{
    char str[]="cat";

    extract(str);
}

    // quote_mode = 0;
    // redir_mode = 0;
    // norm_mode = 0;
    // i = 0;
    // while (str[i])
    // {
    //     if (!ft_is_redi(str[i]) && !ft_is_quote(str[i]))
    //         norm_mode = 1;
    //     else if (ft_is_redi(str[i]))
    //         redir_mode = 1;
    //     else if (ft_is_quote(str[i]))
    //         quote_mode = 1;
        
    // }
