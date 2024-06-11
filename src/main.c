/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouhib <hmouhib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 12:05:51 by agaougao          #+#    #+#             */
/*   Updated: 2024/06/11 20:23:54 by hmouhib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/minishell.h"

void signal_handler(int sig)
{
    char *prompt;

    prompt = "minishell$";
    if (sig == SIGINT)
    {
        printf("\n%s", prompt);
    }
}


int check_builtin(char *str)
{
    if (ft_strncmp(str, "echo",4) == 0)
        return (1);
    else if (ft_strncmp(str, "cd",2) == 0)
        return (2);
    else if (ft_strncmp(str, "pwd",3) == 0)
        return (3);
    else if (ft_strncmp(str, "export",5) == 0)
        return (4);
    else if (ft_strncmp(str, "unset",5) == 0)
        return (5);
    else if (ft_strncmp(str, "env",3) == 0)
        return (6);
    else if (ft_strncmp(str, "exit",4) == 0)
        return (7);
    else
        return (0);
}
void check(char **str, t_minishell *shell)
{
    int s;
    t_list *tmp;
    char *ptr;
    char **split;
    char *path;

    tmp = shell->env;
    s = check_builtin(str[0]);
    if(s != 0)
        builting(str, shell);
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
}

int check_red(c_cmd cmd)
{
    int i;

    i = 0;
    while(cmd.cmd[i]!= NULL)
    {
        if(ft_strncmp(cmd.cmd[i], ">", 1) == 0)
            return (1);
        else if(ft_strncmp(cmd.cmd[i], "<", 1) == 0)
            return (2);
        else if(ft_strncmp(cmd.cmd[i], "<<", 2) == 0)
            return (3);
        i++;
    }
    return (0);
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
void  get_ind(c_cmd cmd)
{
    int i;
    t_red red;
    i = 0;
    int len;
    char *str;
    char *ptr;

    ptr = join_strings(cmd.cmd);
    while(ptr[i])
    {
        len = ft_strlen(ptr);
        if(ptr[i] == '>')
        {
            str = ft_strnstr(ptr , ">" , len);
            red.a_red = ft_strdup(str + 2);
            red.b_red = ft_substr(ptr , 0 , len - ft_strlen(str));
            return;
        }
        else if(ptr[i] == '<')
        {
            str = ft_strnstr(ptr , "<" , len);
            red.a_red = ft_strdup(str + 2);
            red.b_red = ft_substr(ptr , 0 , len - ft_strlen(str));
            return;
        }
        else if(ft_strncmp(ptr, "<<", 2) == 0)
            return;
        i++;
    }
    return;
}
int main(int ac , char **av, char **env)
{
    (void)ac;
    (void)av;
    c_cmd command;
    t_minishell *str;
    char *cmdline;
    int p;
    int i;

    str = malloc(sizeof(t_minishell));
    signal(SIGINT, signal_handler);
    signal(SIGQUIT, SIG_IGN);
    str->env = env_list(env);
    while(1)
    {
        ms_put_prompt();
        cmdline= readline(" ");
        if(cmdline == NULL)
            break;
        command.cmd = ft_split(cmdline, ' ');
        p = check_pipe(command.cmd);
        if(p == 1)
           ; //pipex(command,str);
        else if(check_red(command) == 1)
        {
            get_ind(command);
            red_out(command.cmd,str,0);
        }
        else if(check_red(command) == 2)
        {
            get_ind(command);
            red_in(command.cmd,str);
        }
        // else if(check_red(command) == 3)
        // {
        //     i = get_ind(command);
        //     here_doc();
        // }
        else
            check(command.cmd,str);
        add_history(cmdline);
        free(cmdline);
    }
    free(str);
    return (0);
}
