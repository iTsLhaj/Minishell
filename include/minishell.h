#ifndef MINISHELL_H
# define MINISHELL_H

#include <libft.h>
#include <readline/readline.h>
#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <fcntl.h>
#include<readline/history.h>

/**
 * @brief struct dyaL minishell
 */
typedef struct	s_minishell
{
	t_list *env;

}	t_minishell;

typedef struct cmd
{
	char **cmd;
	int infile;
	int outfile;
} c_cmd;

typedef struct s_env
{
	char	*key;
	char	*val;
}	t_env;
typedef struct s_tmp
{
	char **cmd;
}t_tmp;

typedef struct s_red
{
	char *b_red;
	char *a_red;
}	t_red;
void builting(char **str ,t_minishell *shell);
void miniexit(char **str);
void cd(char **str,int i);
void    pwd(char **str);
void mini_env(t_list *env);
void echo(char **str, int j);
void check_path(char *path,char **str, t_minishell *shell);
t_list *env_list(char **env);
void export(char **str,t_list *list, int i);
void split_env(t_env *env_node, char *str);
void    unset(char **str,t_minishell *shell, int i);
char *check_exist_path(t_list *tmp);
char *check_valid_path(char **ptr, char **str);
int        check_pipe(char **str);
void pipex(c_cmd command , t_minishell *shell);
int check_builtin(char *str);

int red_out(char **str,t_minishell *shell, int i);
void run_builting(char **str,t_minishell *shell, int i);
void check(char **str, t_minishell *shell);
void red_in(char **str, t_minishell *shell);
#endif