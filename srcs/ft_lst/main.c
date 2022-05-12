/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 18:01:26 by samajat           #+#    #+#             */
/*   Updated: 2022/04/24 23:39:12 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int main()
{
	t_list  **stack_A;
// 	t_list  **stack_B;
	
	stack_A = malloc (sizeof (t_list));
	*stack_A = NULL;
	ft_lstadd_front(stack_A, ft_lstnew(1));
	ft_lstadd_front(stack_A, ft_lstnew(7));
	ft_lstadd_front(stack_A, ft_lstnew(4));
	ft_lstadd_front(stack_A, ft_lstnew(5));
	ft_lstadd_front(stack_A, ft_lstnew(8));
	ft_lstadd_front(stack_A, ft_lstnew(3));
	printf("%d\n",ft_get_prelast (stack_A)->content);
}