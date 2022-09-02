
#ifndef MINISHELL_H
#define MINISHELL_H
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <termios.h>
#include <fcntl.h>
#include <dirent.h>
#define PATHNAME_SIZE 512
#define PROMPT "minishell>"
#define PROMPT_ ">"
//sigmal use them
#define NEXE 0
#define EXE 1

//flag for t_cmd.n_type
#define CONTINUE 0
#define SKIP 1
#define PIPE 2
#define AND 3
#define OR 4
#define SYNTAXERROR 5

#define R_PIPE 0
#define W_PIPE 1
#define NEXT_PIPE 2

typedef struct s_info
{

}	t_info;

typedef struct s_cmd
{
	char			**cmd;
	int				pipe[3];
	int				n_type;
	int				ps;
}	t_cmd;

//sig.c
void sigint_handler(int sig);
//envcl.c
char *envcl(char *cl);
//shell_loop.c
void shell_loop(void);

//tool.c
void	itosd(char	*str, int	n);
void	free_list(char	**p);

//mkcmd.c
char    *mkcmd(t_cmd *c, char *cl);
//getcl.c
char *getcl(void);
//exe_line.c
int exe_line(char *cl);

//get_txt.c
char	*get_txt(char *end);

//find.c
char	**find(char **lst);

//asterisk.c
char   	*asterisk(char *cl);

//utils.c
char	*full_file_neme(char	*s);
char	*cm_name(char *s);
char	*skip_tk(char *cl);

//libft_plus.c
char *ft_strstr(const char *s1, const char *s2);

//libft
char	*ft_strjoin(char const	*s1, char const	*s2);


#endif



/* 

#include "minishell.h"

 */
