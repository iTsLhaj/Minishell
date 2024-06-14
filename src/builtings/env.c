/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 18:15:03 by agaougao          #+#    #+#             */
/*   Updated: 2024/06/14 17:20:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/minishell.h"
void mini_env(t_list *env)
{
    while(env)
    {
        if(((t_env *)env->content)->val)
        {
            printf("%s",((t_env *)env->content)->key);
            printf("=%s", ((t_env *)env->content)->val);
            printf("\n");
        }
        env=env->next; 
    }
}
