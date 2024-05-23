/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_envlst_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouhib <hmouhib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 20:15:16 by hmouhib           #+#    #+#             */
/*   Updated: 2024/05/21 20:15:55 by hmouhib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_env_list	*ms_envlst_new(t_env_var *value)
{
	t_env_list  *env_;

	env_ = (t_env_list *)malloc(sizeof(t_env_list));
	env_->evar = value;
	return (env_);
}
