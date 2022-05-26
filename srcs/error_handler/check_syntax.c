/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 15:11:23 by samajat           #+#    #+#             */
/*   Updated: 2022/05/26 00:50:35 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_prenthesis(char	*str)
{
	int	i;
	int	a;
	int	b;
	int	j;

	if ((*g_data.status.exit_code))
		return (0);
	i = -1;
	a = 0;
	b = 0;
	j = ft_strlen (str) - 1;
	while (ft_ispace(str[i]))
		i++;
	while (str[++i] == '(')
		a++;
	while (ft_ispace(str[j]))
		j--;
	while (str[j--] == ')')
		b++;
	if (a == 0 && b == 0)
		return (1);
	chstatus (SYNTAX_ERROR, str, 258);
	return (0);
}

char	*if_prenthesized(char *str, char **t_str)
{
	int	i;
	int	j;

	i = -1;
	j = ft_strlen (str) - 1;
	while (str && ft_ispace(str[i]))
		i++;
	if (str[i++] == '(')
	{
		while (str && str[j] && ft_ispace(str[j]))
			j--;
		if ((str)[j] == ')')
		{
			str = ft_substr(str, i, j - i);
			if (!(str))
				chstatus (MEMORY_LACK, NULL, 30);
			*t_str = str;
			return (str);
		}
		else
			chstatus(SYNTAX_ERROR, NULL, 258);
	}
	*t_str = NULL;
	return (str);
}

int	check_redirection_validity(char *cmd)
{
	return (input_redirection_is_valid(cmd) != 0
		&& output_redirection_is_valid(cmd));
}

int	redirections_are_valid(t_cmd *cmd, char *command)
{
	t_list	*temp;
	char	*element;
	char	*next_element;

	ft_extract_data(cmd, command);
	temp = cmd->ex_elements;
	while (temp && temp->next)
	{
		element = temp->content;
		next_element = temp->next->content;
		if (ft_is_redi(element[0]) && (ft_strlen(element) > 2
				|| ft_is_redi(next_element[0])))
		{
			chstatus (SYNTAX_ERROR, element, 258);
			return (0);
		}
		temp = temp->next;
	}
	return (1);
}

int	check_syntax(t_cmd *cmd, char *command)
{
	if ((*g_data.status.exit_code))
		return (0);
	if (redirections_are_valid(cmd, command))
		return (1);
	return (0);
}
