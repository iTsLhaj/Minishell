/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_init_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouhib <hmouhib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 20:13:24 by hmouhib           #+#    #+#             */
/*   Updated: 2024/05/21 20:14:21 by hmouhib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	set_envars_length(
	int *key_length,
	int *value_length,
	char *envstr
)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (envstr[i] && envstr[i] != '=')
		i++;
	*key_length = i++;
	while (envstr[i + j])
		j++;
	*value_length = j;
}

static t_env_var	*get_env(char *envstr)
{
	int			value_length;
	int			key_length;
	int			i;
	int			j;
	t_env_var	*env;

	set_envars_length(&key_length, &value_length, envstr);
	env = (t_env_var *)malloc(sizeof(t_env_var));
	ft_bzero((void *)env, sizeof(t_env_var));
	env->key = (char *)malloc(key_length + 1);
	env->val = (char *)malloc(value_length + 1);
	i = 0;
	while (envstr[i] && envstr[i] != '=')
	{
		env->key[i] = envstr[i];
		i++;
	}
	j = 0;
	while (envstr[++i])
		env->val[j++] = envstr[i];
	return (env);
}

t_env_list	*ms_init_envs(char **envp)
{
	int			i;
	t_env_list	*envlst;
	t_env_list	*envlrt;

	i = 0;
	envlst = NULL;
	while (envp[i])
	{
		if (envlst == NULL)
		{
			envlst = ms_envlst_new(
				get_env(envp[i]));
			envlrt = envlst;
		}
		else
		{
			envlst->next = ms_envlst_new(
				get_env(envp[i]));
			envlst = envlst->next;
		}
		i++;
	}
	return (envlrt);
}
