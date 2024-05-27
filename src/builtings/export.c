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
        if(((t_env *)env->content)->val)
        {
            printf("declare -x ");
            printf("%s",((t_env *)env->content)->key);
            printf("=%s", ((t_env *)env->content)->val);
            printf("\n");
        }
        env=env->next; 
    }

}
void check_export(c_cmd command,t_list *list)
{
    t_list *new;
    t_env *env;
    int len;
    char *tst;
    char *cmp;
    char *tmp;
    char *add;

    len = ft_strlen(command.cmd[1]);
    tst = ft_strnstr(command.cmd[1],"+=", len);
    if(tst)
    {
        cmp = ft_substr(command.cmd[1],0,len - strlen(tst));
        while(env->key)
        {
            if(ft_strncmp(env->key, cmp , strlen(cmp)) == 0)
            {
                printf("dd\n");
                env->val=ft_strjoin(env->val,tst);
                while(list)
                {
                    if(ft_strncmp(list->content, cmp , strlen(cmp)) == 0)
                    {
                        tmp = ft_strnstr(list->content, "=", ft_strlen(list->content));
                        add = ft_strjoin(tmp, tst);                            
                        new = ft_lstnew(add);
                        ft_lstadd_back(&list,new);
                    }
                    list = list->next;
                }
            }                
        }

    }
    else
    {
        env = malloc(sizeof(t_env));
        split_env(env,command.cmd[1]);
        new = ft_lstnew(env);
        ft_lstadd_back(&list,new);
    }
}
void export(c_cmd command,t_list *list)
{

    if(ft_strncmp(command.cmd[0] , "export", 5) == 0)
    {
        if(command.cmd[1] == NULL)
            declare(command,list);
        else if(command.cmd[1])
        {
           check_export(command,list);
        }
    }
}
