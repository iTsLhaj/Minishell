/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_envlst_getter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouhib <hmouhib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 20:13:24 by hmouhib           #+#    #+#             */
/*   Updated: 2024/05/23 13:04:34 by hmouhib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*ms_get_env(t_minishell *shell, char *key)
{
	t_env_list	*envs;

	envs = shell->envlist;
	while (envs)
	{
		if (!ft_strncmp(
			key, envs->evar->key,
			ft_strlen(key)))
			return (envs->evar->val);
		envs = envs->next;
	}
	return (NULL);
}
