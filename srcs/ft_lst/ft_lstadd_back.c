#include "minishell.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	temp = ft_lstlast(*lst);
	if (temp)
		temp -> next = new;
	else if (temp == NULL)
		*lst = new;
}

void	ft_token_add_back(t_token **token, t_token *new)
{
	t_token	*temp;

	temp = ft_tokenlast(*token);
	if (temp)
		temp -> next = new;
	else if (temp == NULL)
		*token = new;
}

void	ft_env_tadd_back(t_env **lst, t_env *new)
{
	if (!new)
		return ;
	if (!(*lst))
		*lst = new;
	else
		ft_env_last((*lst))->next = new;
}
