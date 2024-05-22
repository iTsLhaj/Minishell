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

/**
 * @brief struct dyaL minishell
 */
typedef struct	s_minishell
{
	void	*data;
	int	quit;
}	t_minishell;

typedef struct cmd
{
	char **cmd;
	char *oldpwd;
	char **env;
} c_cmd;

typedef struct env
{
	void	*data;
	struct env *next;
} t_env;

void builting(c_cmd command , char **env);
void miniexit(c_cmd command);
void cd(c_cmd *cmd , char **env);
void    pwd(c_cmd *cmd);
void mini_env(c_cmd command,char **env);
void echo(c_cmd *cmd);
#endif
