
#include "minishell.h"

t_list	*ft_lstnew(void *content, int   type)
{
	t_list	*node;

	node = (struct s_list *) malloc (sizeof(struct s_list));
	if (!node)
    {
        chstatus(MEMORY_LACK, NULL, 30);
        return (NULL);
    }
    if (type == INT)
	    node -> content = (int *)content;
    else
	    node -> content = (char *)content;
	node -> next = NULL;
	return (node);
}

t_token	*ft_token_new(t_spliter *t_sep)
{
	t_token	*node;

	node = (t_token *) malloc (sizeof(t_token));
	if (!node)
    {
        chstatus(MEMORY_LACK, NULL, 30);
        return (NULL);
    }
	node -> sep = t_sep;
	node -> next = NULL;
	return (node);
}

t_env	*ft_env_new(char *var, char *val)
{
	t_env	*first_list;
	first_list = (t_env *)malloc(sizeof(t_env));
	if (first_list == NULL)
		return (NULL);
	first_list->variable = var;
	first_list->value = val;
	first_list->next = NULL;
	return (first_list);
}

