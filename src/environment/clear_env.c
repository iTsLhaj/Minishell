/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouhib <hmouhib@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 05:57:50 by hmouhib           #+#    #+#             */
/*   Updated: 2024/06/01 05:58:18 by hmouhib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	clear_env(void *content)
{
	t_env_var	*content_t;

	content_t = (t_env_var *)content;
	free(content_t->key);
	free(content_t->val);
	free(content_t);
}
