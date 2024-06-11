/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_getter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouhib <hmouhib@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 19:53:52 by hmouhib           #+#    #+#             */
/*   Updated: 2024/05/24 20:24:15 by hmouhib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*ms_get_env(t_list *envlst, char *key)
{
	t_list	*elst;

	if (envlst == NULL || key == NULL)
		return (NULL);
	elst = envlst;
	if (key[0] == '$')
		key = &key[1];
	while (elst)
	{
		if (!ft_strncmp(
				key,
				((t_env_var *)(elst->content))->key, ft_strlen(key)
		))
			return ((((t_env_var *)(elst->content)))->val);
		elst = elst->next;
	}
	return (NULL);
}
