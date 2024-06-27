/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 09:48:04 by agaougao          #+#    #+#             */
/*   Updated: 2024/06/26 16:06:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<minishell.h>

int here_doc(t_minishell *shell)
{
    char *promp;
    t_command *command;
    t_token *redirection;
    char *data;
    int pid;
    t_list *tmp;
    char **cmdline;
    tmp = shell->envlst;
    data = NULL;
    command = (t_command *)(shell->commands->content);
    redirection = (t_token *)(command->redirections->content);
    cmdline = command->cmd_argv;
    pid =  fork();
    if(pid == 0)
    {
        while(1)
        {
            promp = readline("> ");
            if(ft_strncmp(promp, redirection->word, ft_strlen(promp)) == 0)
            {
                free(promp);
                break;
            }
            ft_strjoin(data, promp);
            free(promp);
        }
        if(check_builtin(cmdline[0]))
        {
            builting(cmdline, shell);
        }
        else if(check_exist_path(tmp) != NULL)
        {
            check(shell);
        }
    }
    else
        waitpid(pid,NULL,0);
    return (1);
}