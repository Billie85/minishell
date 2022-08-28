
#ifndef MINISHELL_H
#define MINISHELL_H
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <termios.h>
#define PROMPT "minishell>"
#define PROMPT_ ">"
#define NEXE 0
#define EXE 1
#define DEFALT 0
#define REDIRECT 1
//flag for t_cmd.n_type
#define NOCMD 0
#define NEXT 1
#define PIPE 2
#define AND 3
#define OR 4

#define R_PIPE 0
#define W_PIPE 1
#define NEXT_PIPE 2

typedef struct s_info
{

}	t_info;

typedef struct s_cmd
{
	char			**cmd;
	int				r_fd;
	int				w_fd;
	int				n_type;
}	t_cmd;

//sig.c
void sigint_handler(int sig);
//envcl.c
char *etcl(char *cl);

#endif



/* 

#include "minishell.h"

 */
