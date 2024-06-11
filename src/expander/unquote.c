/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unquote.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouhib <hmouhib@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:00 by hmouhib           #+#    #+#             */
/*   Updated: 2024/06/10 19:42:40 by hmouhib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static char	*unquote_string(char *string)
{
	char	*unquoted_string;
	int		quotes_counter;
	int		i;

	quotes_counter = 0;
	i = 0;
	while (string[i])
	{
		if (string[i] == 34 || string[i] == 39)
			quotes_counter++;
		i++;
	}
	if (!quotes_counter)
		return (NULL);
	unquoted_string = (char *)ft_calloc(
		ft_strlen(string) - quotes_counter, sizeof(char));
	i = 0;
	while (*string)
	{
		if (*string == 34 || *string == 39)
			string++;
		else
		{
			unquoted_string[i++] = *string;
			string++;
		}
	}
	unquoted_string[i] = 0;
	return (unquoted_string);
}

void	unquote(t_list *lexerlist)
{
	t_token	*data;
	char	*temp;

	while (lexerlist)
	{
		data = lexerlist->content;
		temp = unquote_string(data->word);
		// printf("%s\n", temp);
		if (temp != NULL)
		{
			free(data->word);
			data->word = ft_strdup(temp);
			free(temp);
		}
		lexerlist = lexerlist->next;
	}
}
