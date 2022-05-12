
#include "minishell.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*temp;

	temp = lst;
	if (temp != NULL)
		while (temp->next)
			temp = temp->next;
	return (temp);
}

t_token	*ft_tokenlast(t_token *token)
{
	t_token	*temp;

	temp = token;
	if (temp != NULL)
		while (temp->next)
			temp = temp->next;
	return (temp);
}

t_env	*ft_env_last(t_env *lst)
{
	t_env	*current;

	current = lst;
	if (lst == NULL)
		return (NULL);
	while (current->next)
		current = current->next;
	return (current);
}

