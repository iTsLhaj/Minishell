/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaougao <agaougao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 09:48:04 by agaougao          #+#    #+#             */
/*   Updated: 2024/06/27 11:52:53 by agaougao         ###   ########.fr       */
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
    int fd;
    int in = dup(0);
    tmp = shell->envlst;
    data = NULL;
    command = (t_command *)(shell->commands->content);
    redirection = (t_token *)(command->redirections->content);
    cmdline = command->cmd_argv;
    fd = open("../../here_doc", O_RDWR | O_CREAT | O_TRUNC , S_IRWXU, 0644);
    pid =  fork();
        if(pid == 0)
        {
            if(fd != -1)
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
                if(check_builtin(cmdline[0]))
                {
                    dup2(fd, 0);
                    close(fd);
                    builting(cmdline, shell);
                }
                else if(check_exist_path(tmp) != NULL)
                {
                    dup2(fd, 0);
                    close(fd);
                    check(shell);
                }
            }
            dup2(in, 0);
    }
    else
        waitpid(pid,NULL,0);
    return (1);
}
