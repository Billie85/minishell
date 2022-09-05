# ifndef MINISHELL_H
#define MINISHELL_H
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
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
#define PROMPT "minishell2>"
#define PROMPT_ ">"
//sigmal use them
#define READING 0X00
#define EXEING 0X01
#define SIGCOME 0X10

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

//libft
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strjoin(char const	*s1, char const	*s2);
size_t	count_long(char const *s);

//asterisk.c
char	*asterisk(char *cl);
char	*as_std(char *cl, size_t B);
char	**as_as_list(char *cl, size_t dw);
char	*as_as_std(char *cl, char **cln, size_t B);
char	*as_as_q(char *cl, char **cln, size_t B, char c);

//bul
int bul_cd(int argc, char *argv[]);
int bul_echo(int argc, char *argv[]);
int is_opn(char *s);
int bul_env(int argc, char *argv[]);
int bul_export(int argc, char *argv[]);
int bul_pwd(int argc, char *argv[]);
int bul_unset(int argc, char *argv[]);

//envcl.c
char	*envcl(char *cl);
char	*ecl_std(char	*cl, size_t	B);
char	*ecl_sp(char *cl, size_t B);
char	*ecl_dq(char	*cl, size_t	B);
char	*ecl_sq(char	*cl, size_t	B);
char	*ecl_env_std(char *cl, size_t B);
char	*ecl_env_dq(char *cl, size_t B);
char	*extractenv(char *cl);

//find.c
char	**find(char **lst);
char	**fi_list(char *search);
void	fi_dir(char **r);
int		fi_ok(char *str, char **l);

//getck.c
char	*getcl(void);
char	*gcl_std(char	*cl, size_t	B);
char	*gcl_dq(char	*cl, size_t	B);
char	*gcl_sq(char *cl, size_t B);
char	*gcl_nc(char	*cl, size_t	B);

//mkcmd.c
char	*mkcmd(t_cmd *c, char *cl);
char	**cmdlist(t_cmd *c, char *cl, char **ncl, size_t ll);
char	*tk_std(char *cl, size_t B);
char	*tk_dq(char *cl, size_t B);
char	*tk_sq(char *cl, size_t B);
char	*tk_ques(char *cl, size_t B, char *(*f)(char *, size_t));

//cm_names.c
char	*cm_name3(char *p, char *s, char *r);
char	*cm_name2(char *p, char *s);
char	*cm_name1(char *s);
char	*cm_name(char *s);

//env.c
char	**ev(char **set);
char	*get_env(char *s);
int		set_env(char *name, char *arg);
char	**env_space(char *s);
int		rm_env(char *s);

//exe_bulitin.c
int	isbulitin(char *s);
void	exe_bulitin3(t_cmd *c);
void	exe_bulitin2(t_cmd *c);
int		exe_bulitin(t_cmd *c);

//exe_cmd.c
int		exe2(t_cmd *c);
int		exe_cmd(t_cmd *c);
int		exe_cmd1(t_cmd *c);
void	exe_start(t_cmd *c, char *cm);

//exe_line.c
int	exe_line(char *cl);
void	cleanc(t_cmd *c);

//free.c
void	free_list(char	**p);
void	*free_return(void *p, void *r);
void	*free_list_return(void *l, void *r);

//get_txt.c
char	*get_txt(char *end);
char	*gt_std(char *end, size_t B);
char	*gt_mkmem(char *f, size_t B);

//main.c
void	preexe(char **envp);

//shell_loop.c
void	shell_loop(void);

//sig2.c
void	sigint_handler(int sig);
void	sigquit_handler(int sig);

//tool.c
char	**cpy_list(char	**p);
char	**cpy_list_std(char	**p, size_t dw);
size_t	list_len(char **l);
void	*m_error(void);

//tosd.c
void	itosd(char *str, int n);
void	itosd1(char	*str, int n);

//ultils.c
char	*full_file_neme(char	*s);
char	*skip_tk(char *cl);

#endif