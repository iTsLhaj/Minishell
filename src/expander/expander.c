/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouhib <hmouhib@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:00 by hmouhib           #+#    #+#             */
/*   Updated: 2024/06/24 22:35:59 by hmouhib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int	get_biggest(t_list *envlst)
{
	int	biggest;

	biggest = 0;
	while (envlst)
	{
		if (biggest < ft_strlen(
			((t_env_var *)(envlst->content))->val))
			biggest = ft_strlen(
			((t_env_var *)(envlst->content))->val);
		envlst = envlst->next;
	}
	return (biggest);
}

char    *expander(t_minishell *shell, const char *token)
{
	char	*expanded_token;
	char	*expanded_value;
	char	*temp;
	int		start;
	int		i;
	int		j;

	if (token == NULL)
		return NULL;
	expanded_token = (char *)calloc(
		1, (get_biggest(shell->envlst) + 1));
	i = 0;
	j = 0;
	while (token[i])
	{
		if (token[i] == '$' && token[i + 1] != '\0')
		{
			i++;
			start = i;
			while (token[i] && (ft_isalnum(token[i]) || token[i] == '_'))
				i++;
			expanded_value = ft_substr(token, start, i - start);
			temp = ms_get_env(shell->envlst, expanded_value);
			free(expanded_value);
			expanded_value = temp;
			if (expanded_value != NULL)
			{
				ft_strlcpy(
					&expanded_token[j],
					expanded_value,
					ft_strlen(expanded_value) + 1
				);
				j += ft_strlen(expanded_value);
				// free(expanded_value);
			}
		}
		else
			expanded_token[j++] = token[i++];
	}
	expanded_token[j] = 0;
	return (expanded_token);
}

void	extend(t_minishell *shell)
{
	t_list		*lxrlst;
	t_token		*data;
	char		*temp;
	char		*token;
	char		*etok;

	lxrlst = shell->lexerlst;

	/**
		@note pls note that i removed the unquote function call
		@note it was called above while (lxrlst) line !
		@note already called in the main function so
		@note so i tought there's no need to recall it here
		(its useless in other words !)
	*/
	while (lxrlst)
	{
		data = lxrlst->content;
		token = data->word;

		/// < expanding logic here >
		// printf("expanding <%s>\n", token);
		etok = expander(shell, token);
		if (etok != NULL)
			data->word = ft_strdup(etok);
		free(token);
		lxrlst = lxrlst->next;
	}
}
