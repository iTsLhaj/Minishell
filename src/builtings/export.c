/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaougao <agaougao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:35:29 by agaougao          #+#    #+#             */
/*   Updated: 2024/05/26 10:36:11 by agaougao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
void declare(c_cmd command,t_list *env)
{
    while(env)
    {
        printf("=%s", ((t_env *)env->content)->val);
        if(((t_env *)env->content)->val)
        {
            printf("declare -x");
            printf("%s",((t_env *)env->content)->key);
            printf("=%s", ((t_env *)env->content)->val);
            printf("\n");
        }
        env=env->next; 
    }

}
void export(c_cmd command,t_list *list)
{
    if(ft_strncmp(command.cmd[0] , "export", 5) == 0)
    {
        if(command.cmd[1] == NULL)
        {
            // printf("%s",((t_env *)env->content)->key);
            // printf("=%s", ((t_env *)node->env->content)->val);
            // printf("\n");
            // declare(command,node->env);
        }
        else if(command.cmd[1])
        {
           list = env_list(&command.cmd[1]);
        }
    }
}