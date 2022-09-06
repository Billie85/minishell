#ifndef MINISHELL_H
# define MINISHELL_H
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <termios.h>
# include <fcntl.h>
# include <dirent.h>
# define PATHNAME_SIZE 512
# define PROMPT "minishell>"
# define PROMPT_ ">"
//sigmal use them
# define READING 0X00
# define EXEING 0X01
# define SIGCOME 0X10

//flag for t_cmd.n_type
# define CONTINUE 0
# define SKIP 1
# define PIPE 2
# define AND 3
# define OR 4
# define SYNTAXERROR 5

# define R_PIPE 0
# define W_PIPE 1
# define NEXT_PIPE 2

typedef struct s_g
{
	int	status;
	int	exeret;
}	t_g;

typedef struct s_cmd
{
	char	**cmd;
	int		pipe[3];
	int		n_type;
	int		ps;
}	t_cmd;

//bulitin
int		bul_cd(int argc, char *argv[]);
int		bul_echo(int argc, char *argv[]);
int		bul_env(int argc, char *argv[]);
int		bul_export(int argc, char *argv[]);
int		bul_pwd(int argc, char *argv[]);
int		bul_unset(int argc, char *argv[]);

//sig.c
void	sigint_handler(int sig);
void	sigquit_handler(int sig);
//envcl.c
char	*envcl(char *cl);
//shell_loop.c
void	shell_loop(void);

//tool.c
void	itosd(char *str, int n);
void	free_list(char	**p);
char	**cpy_list(char	**p);
size_t	list_len(char **l);
void	*m_error(void);
void	*free_return(void *p, void *r);
void	*free_list_return(void *l, void *r);
int		ep3(char *s1, char *s2, char *s3);

//evn.c
char	**ev(char **set);
char	*get_env(char *s);
int		set_env(char *name, char *arg);
int		rm_env(char *s);

//exe_bulitin.c
int		isbulitin(char *s);
int		exe_bulitin(t_cmd *c);

//mkcmd.c
char	*mkcmd(t_cmd *c, char *cl);
//getcl.c
char	*getcl(void);
//exe_line.c
int		exe_line(char *cl);

//get_txt.c
char	*get_txt(char *end);

//find.c
char	**find(char **lst);

//asterisk.c
char	*asterisk(char *cl);

//utils.c
char	*cm_name(char *s);
char	*skip_tk(char *cl);

//libft_plus.c
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strstr(const char *s1, const char *s2);

//libft
int		ft_isalpha(int c);
int		ft_isalnum(int c);
size_t	ft_strlen(const char *str);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s1);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strjoin(char const *s1, char const *s2);


#endif
