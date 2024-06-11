/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaougao <agaougao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 18:15:03 by agaougao          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/05/22 11:42:48 by agaougao         ###   ########.fr       */
=======
/*   Updated: 2024/05/30 16:27:09 by agaougao         ###   ########.fr       */
>>>>>>> origin/exec
/*                                                                            */
/* ************************************************************************** */

#include"../include/minishell.h"
<<<<<<< HEAD

void mini_env(c_cmd command,char **env)
{
    int i;
    (void)env;
    
    i = 0;
    
    if(ft_strncmp(command.cmd[0] ,"env",3) == 0)
    {
        while(command.env[i] != NULL)
        {
            printf("%s\n",command.env[i]);
            i++;
        }
=======
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
>>>>>>> origin/exec
    }
}
