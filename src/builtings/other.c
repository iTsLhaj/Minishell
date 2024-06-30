/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouhib <hmouhib@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by hmouhib           #+#    #+#             */
/*   Updated: 2024/06/30 18:21:09 by hmouhib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int check_red(t_minishell *shell , t_command *command)
{
	t_token *redirection;
	int stat;

	stat = 0;
	if (command->redirections == NULL)
		return 0;
	while(command->redirections)
	{
		redirection = (t_token *)(command->redirections->content);
		if(redirection->token == TRUNCATE)
			stat = red_out(shell,command);
		else if(redirection->token == HEREDOC)
		{
			if(stat != 2)
				stat =  here_doc(shell,command);
			else if(command->redirections == NULL)
				break;
		}
		else if(redirection->token == REDIRECT_INPUT)
			stat = red_in(shell,command);
		else if(redirection->token == APPEND)
			stat = append_red(shell,command);
		command->redirections = command->redirections->next;
	}
	return (stat);
}

void check(t_minishell *shell , t_command *command)
{
    int s;
    t_list *tmp;
    char *ptr;
    char **split;
    char *path;
    char **str;


    tmp = shell->envlst;
    // while(shell->commands)
    // {
        str =  ((t_command *)shell->commands->content)->cmd_argv;
        s = check_builtin(str[0]);
        if(s != 0)
            builting(str,shell);
        else
        {
            ptr = check_exist_path(tmp);
            if(ptr == NULL)
                printf(" %s: No such file or directory\n", str[0]);
            else
            {
                split = ft_split(ptr , ':');
                path = check_valid_path(str , split);
                if(path != NULL)
                    check_path(path, str,shell);
                else
                    printf("%s: command not found\n", str[0]);
            }
        }
    // }
    // shell->commands = shell->commands->next;
}

char  *join_strings(char **cmd)
{
    char *str;
    // char *ptr;
    int i;

    i = 0;
    str = NULL;
    while(cmd[i])
    {
        str = ft_strjoin(str, cmd[i]);
        if(cmd[i + 1] == NULL)
            break;
        str = ft_strjoin(str, " ");
        i++;
    }
    return (str);
}
