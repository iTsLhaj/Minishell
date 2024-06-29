/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaougao <agaougao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 14:23:17 by agaougao          #+#    #+#             */
/*   Updated: 2024/06/29 13:14:32 by agaougao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/minishell.h"


int check_pipe(t_minishell *shell)
{
    t_command *command;
    t_command *nex_command;
    while(shell->commands->next)
    {
        command = (t_command *)(shell->commands->content);
        nex_command = (t_command *)(shell->commands->next->content);
        pipex(shell, command , nex_command);
        shell->commands = shell->commands->next;
    }
    return (0);
}