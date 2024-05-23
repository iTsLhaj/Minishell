/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_tokutils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouhib <hmouhib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 03:24:01 by hmouhib           #+#    #+#             */
/*   Updated: 2024/05/23 03:39:14 by hmouhib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_list	*append(
	t_list *parse_list,
	t_list **l_root,
	char *value
)
{
	if (parse_list == NULL)
	{
		parse_list = (t_list *)malloc(sizeof(t_list));
		ft_bzero((void *)parse_list, sizeof(t_list));
		parse_list->val = ft_strdup(value);
		parse_list->next = NULL;
		*l_root = parse_list;
	}
	else
	{
		parse_list->next = (t_list *)malloc(sizeof(t_list));
		parse_list = parse_list->next;
		ft_bzero((void *)parse_list, sizeof(t_list));
		parse_list->val = ft_strdup(value);
		parse_list->next = NULL;
	}
	ft_bzero((void *)value, 1024);
	return (parse_list);
}

void	hq(
	int	*in_q,
	char chr,
	int *quote,
	char *token
)
{
	if (*in_q && chr == *quote)
	{
		*in_q = 0;
		*quote = 0;
	}
	else if (!(*in_q))
	{
		*in_q = 1;
		*quote = chr;
	}
	else
		*token = chr;
}

void	free_llist(t_list *list)
{
	if (list == NULL)
		return ;
	free_llist(list->next);
	free(list->val);
	free(list);
}
