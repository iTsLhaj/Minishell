/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unquote.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouhib <hmouhib@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:00 by hmouhib           #+#    #+#             */
/*   Updated: 2024/06/16 16:56:18 by hmouhib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static char	*unquote_string(char *string)
{
	char	*unquoted_string;
	int		quotes_counter;
	int		i;

	if (string == NULL)
		return (NULL);
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

char 	*purify_empty_quotes(char *line_read)
{
	int 	i;
	int 	j;
	int 	k;
	char 	*purified;

	k = 0;
	purified = (char *)(
		calloc(ft_strlen(line_read), sizeof(char)));
	i = 0;
	while (i < ft_strlen(line_read))
	{
		j = i + 1;
		if ((line_read[i] == 34 || line_read[i] == 39)
			&& line_read[i] == line_read[j])
			i += 2;
		else
			purified[k++] = line_read[i++];
	}
	free(line_read);
	return (purified);
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
