
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
#define EXE 1
#define NEXE 0
#define DEFALT 0
#define REDIRECT 1
//flag for t_cmd.n_type
#define NOCMD 0

typedef struct s_info
{

}	t_info;

typedef struct s_cmd
{
	char			**cmd;
	int				i_type;
	char			*i_neme;
	int				o_type;
	char			*o_neme;
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
