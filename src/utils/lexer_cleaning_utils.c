/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_cleaning_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouhib <hmouhib@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 23:58:58 by hmouhib           #+#    #+#             */
/*   Updated: 2024/06/09 00:05:11 by hmouhib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	clean_content(void *content)
{
	t_token	*content_t;

	content_t = (t_token *)content;
	if (content_t->word != NULL)
		free(content_t->word);
	free(content_t);
}

void	clear_first_node(t_list **lexer_list)
{
	t_list	*temp;

	temp = *lexer_list;
	*lexer_list = (*lexer_list)->next;
	if (*lexer_list)
		(*lexer_list)->prev = NULL;
	ft_lstdelone(temp, &clean_content);
}

void	lexer_delone(t_list **lexer_list, int key)
{
	t_list	*target;
	t_list	*p;

	if (((t_token *)(*lexer_list)->content)->key == key)
	{
		clear_first_node(lexer_list);
		return ;
	}
	target = *lexer_list;
	while (target && ((t_token *)(target->content))->key != key)
	{
		p = target;
		target = target->next;
	}
	if (target == NULL)
		return ;
	p->next = target->next;
	if (p->next != NULL)
		p->next->prev = p;
	ft_lstdelone(target, &clean_content);
}
