/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaougao <agaougao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 14:32:39 by agaougao          #+#    #+#             */
/*   Updated: 2024/06/02 16:44:25 by agaougao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_list *turn_to_list(c_cmd command)
{
    t_tmp *tmp;
    t_list *new;
    t_list *head;
    int i;

    head = NULL;
    i = 0;
    while(command.cmd[i])
    {
        tmp = malloc(sizeof(t_tmp));
        tmp->cmd = command.cmd[i];
        new = ft_lstnew(tmp);
        ft_lstadd_back(&head , new);
        i++;
    }
    return(head);
}

void pipex(c_cmd cmd , t_minishell *shell)
{
    t_list *list;
    char *str;
    c_cmd *command;
    list = turn_to_list(cmd);

    int i;

    i = 0;
    while(list)
    {
        str = ((t_tmp *)list->content)->cmd;
        if(check_builtin(str))
        {
            command = ((c_cmd *)list->content);
            builting(*command,shell);
        }
        list = list->next;
    }
}
