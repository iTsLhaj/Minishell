/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_environment.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouhib <hmouhib@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 19:37:11 by hmouhib           #+#    #+#             */
/*   Updated: 2024/05/24 20:11:42 by hmouhib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	set_length(
	int *key_length,
	int *value_length,
	char *estr
)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (estr[i] && estr[i] != '=')
		i++;
	*key_length = i++;
	while (estr[i + j])
		j++;
	*value_length = j;
}

static t_env_var	*get_env(char *estr)
{
	int			val_len;
	int			key_len;
	int			i;
	int			j;
	t_env_var	*env;

	set_length(&key_len, &val_len, estr);
	env = (t_env_var *)malloc(sizeof(t_env_var));
	ft_bzero((void *)env, sizeof(t_env_var));
	env->key = (char *)malloc(key_len + 1);
	ft_bzero((void *)env->key, key_len + 1);
	env->val = (char *)malloc(val_len + 1);
	ft_bzero((void *)env->val, val_len + 1);
	i = 0;
	while (estr[i] && estr[i] != '=')
	{
		env->key[i] = estr[i];
		i++;
	}
	j = 0;
	while (estr[++i])
		env->val[j++] = estr[i];
	return (env);
}

t_list	*ms_init_env(char **envp)
{
	int		i;
	t_list	*lst;
	t_list	*head;

	i = 0;
	lst = NULL;
	while (envp[i])
	{
		if (lst == NULL)
		{
			lst = ft_lstnew((void *)get_env(envp[i]));
			head = lst;
		}
		else
		{
			lst->next = ft_lstnew((void *)get_env(envp[i]));
			lst = lst->next;
		}
		i++;
	}
	return (head);
}
