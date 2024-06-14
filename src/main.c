/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 12:05:51 by agaougao          #+#    #+#             */
/*   Updated: 2024/06/14 19:58:18 by hmouhib          ###   ########.fr       */
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

void	init_shell(t_minishell *shell, char **envp)
{
    shell->envlst = ms_init_env(envp);
    shell->lexerlst = NULL;
    shell->input = NULL;
    shell->commands = NULL;
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

void check(char **str, t_minihell *shell)
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

int check_red(t_cmd cmd)
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
void  get_ind(t_cmd cmd)
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
    t_minishell *shell;
    t_cmd command;
    int p;
    int i;

    shell = malloc(sizeof(t_minishell));
    signal(SIGINT, signal_handler);
    signal(SIGQUIT, SIG_IGN);
    shell->envlst = env_list(env);
    init_shell(shell, env);
    while(1)
    {
        ms_put_prompt();
        shell->input = readline(" ");
        if(shell->input == NULL)
            break;
        if (!check_quotes(shell->input))
        {
            tokenize_input(shell);
            unquote(shell->lexerlst);
            /** @brief ... skip the extending part since mazal masalitha ! */
            /// <extend here>
            if (shell->lexerlst)
                parser(shell);
        }
        else
            printf("syntax error: unclosed quote !\n");
        command = shell->commands->content;
        p = check_pipe(command.cmd);
        check(command.cmd, shell);
        add_history(shell->input);
        free(cmdline);
    }
    ft_lstclear(&shell->lexerlst, &clean_content);
    free(shell);
    return (0);
}
