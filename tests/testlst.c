#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_env
{
    char *variable;
    char *value;
    struct s_env *next;
}   t_env;

t_env    *ft_env_last(t_env *lst)
{
    t_env    *current;

    current = lst;
    if (current != NULL)
        while (current->next)
            current = current->next;
    return (current);
}

t_env    *ft_env_new(char *var, char *val)
{
    t_env    *first_list;
    first_list = (t_env *)malloc(sizeof(t_env));
    if (first_list == NULL)
        return (NULL);
    first_list->variable = var;
    first_list->value = val;
    first_list->next = NULL;
    return (first_list);
}

void    ft_env_tadd_back(t_env **env, t_env *new)
{
    t_env *temp;
     temp = ft_env_last(*env);
    if (!new)
        return ;
    if (temp)
        temp -> next = new;
    else if (temp == NULL)
        *env = new;
}

int main() {
  t_env *en;
  en = malloc(sizeof(t_env));
  ft_env_tadd_back(en, ft_env_new("mehdi", "mohammady"));
  puts("ok\n");
  return 0;
}