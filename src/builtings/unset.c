/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaougao <agaougao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 12:08:28 by agaougao          #+#    #+#             */
/*   Updated: 2024/05/30 16:27:13 by agaougao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	del(void *ptr)
{
	free(ptr);
	ptr = NULL;
}
void del_the_env(t_minishell *shell, t_list *lst)
{
    t_list *tmp;
    
    tmp = shell->env;
    while(tmp->next != lst)
        tmp = tmp->next;
    if(tmp->next)
        tmp->next=lst->next;
    else
        tmp->next = NULL;
    free(((t_env *)(lst->content))->key);
    free(((t_env *)(lst->content))->val);
    ft_lstdelone(lst,del);
    
}

t_list *get_the_env(char *key, t_list *list)
{
    t_list *tmp;

    tmp = list;
    while(tmp)
    {
        if(ft_strncmp(((t_env *)(tmp->content))->key,key,ft_strlen(key)) == 0)
            return tmp;
        tmp = tmp->next;
    }
    return NULL;
}
int o_check_key(c_cmd cmd,t_list *list)
{
    char *key;

    while(list)
    {
        key = ((t_env *)(list->content))->key;
        if(ft_strncmp(key,cmd.cmd[1],ft_strlen(key) ) == 0)
            return 1;
        list = list->next;
    }
    return 0;
}
void    unset(c_cmd cmd,t_minishell *shell)
{
    t_list *lst;
    if(ft_strncmp(cmd.cmd[0], "unset",5) == 0)
    {
        if(o_check_key(cmd,shell->env) == 1)
        {
            lst = get_the_env(cmd.cmd[1], shell->env);
            del_the_env(shell, lst);    
        }        
    }
}
