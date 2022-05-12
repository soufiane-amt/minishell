
#include "minishell.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new -> next = (*lst);
	(*lst) = new;
}

void	ft_token_add_front(t_token **lst, t_token *new)
{
	new -> next = (*lst);
	(*lst) = new;
}
