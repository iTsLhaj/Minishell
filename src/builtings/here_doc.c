/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaougao <agaougao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 09:48:04 by agaougao          #+#    #+#             */
/*   Updated: 2024/06/29 11:21:18 by agaougao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<minishell.h>

int here_doc(t_minishell *shell, t_command *command)
{
    char *promp;
    t_token *redirection;
    int pid;
    t_list *tmp;
    char **cmdline;
    int fd;
    int fd1;
    int in = dup(0);
    
    tmp = shell->envlst;
    cmdline = command->cmd_argv;
    pid =  fork();
    if(pid == 0)
    {
        while(command->redirections)
        {
            redirection = (t_token *)(command->redirections->content);
            fd = open("here_doc",O_RDWR | O_CREAT | O_TRUNC);
            if(fd != -1)
            {
                if(redirection->token == HEREDOC)
                {
                    while(1)
                    {
                        promp = readline("> ");
                        if(ft_strncmp(promp, redirection->word, ft_strlen(promp)) == 0)
                        {
                            free(promp);
                            break;
                        }
                        write(fd, promp, ft_strlen(promp));
                        write(fd, "\n",1);
                        free(promp);
                    }
                }
            }
            command->redirections = command->redirections->next;
        }
        fd1 = open("here_doc", O_RDWR);
        if(fd1 != -1)
        {       
            if(check_builtin(cmdline[0]))
            {
                dup2(fd1, 0);
                close(fd1);
                builting(cmdline, shell);
            }
            else if(check_exist_path(tmp) != NULL)
            {
                dup2(fd1, 0);
                close(fd1);
                check(shell,command);
            }
        }
        dup2(in, 0);
        exit(0);
    }
    waitpid(pid,NULL,0);
    return (2);
}
