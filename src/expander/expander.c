/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouhib <hmouhib@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:00 by hmouhib           #+#    #+#             */
/*   Updated: 2024/06/10 05:51:05 by hmouhib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	extend(t_minishell *shell)
{
	t_list	*lxrlst;
	t_token	*data;
	char	*temp;

	lxrlst = shell->lexerlst;
	unquote(lxrlst);
	while (lxrlst)
	{
		data = lxrlst->content;
		if (data->word[0] == '$')
		{
			temp = ms_get_env(shell->envlst, data->word);
			free(data->word);
			if (temp != NULL)
			{
				data->word = ft_strdup(temp);
				free(temp);
			}
			else
				data->word = ft_strdup("");
		}
		lxrlst = lxrlst->next;
	}
	lxrlst = shell->lexerlst;
	while (lxrlst)
	{
		data = lxrlst->content;
		printf("<-------------->\nword : %s\ntoken: %s\n<-------------->\n",
			data->word, stringify_token(data->token));
		lxrlst = lxrlst->next;
	}
}
