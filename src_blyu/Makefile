NAME	= minishell

ASTERISK_SRCS	= 0_asterisk.c as_as_list.c as_as_q.c as_as_std.c as_stdA.c as_stdB.c

BULITIN_SRCS	= bul_cd.c bul_echo.c bul_env.c bul_export.c bul_pwd.c bul_unset.c

ENVCL_SRCS		= 0_envcl.c ecl_env_dq.c ecl_sp.c ecl_stdA.c \
ecl_dq.c ecl_env_std.c ecl_sq.c ecl_stdB.c extractenv.c

FIND_SRCS		= 0_find.c fi_dir.c fi_list.c fi_ok.c fi_std.c

GETCl_SRCS		= 0_getcl_g.c gcl_dq.c gcl_nc.c gcl_sq.c gcl_stdA.c gcl_stdB.c

MKCMD_SRCS		= 0_mkcmd.c cmdlistB.c tk_ques_g.c tk_stdA.c \
cmdlistA.c cmdlistC.c tk_dq.c tk_sq.c tk_stdB.c

LIBFT_PULUS		= zzz_libft.c

SRCS			= exe_bulitin_g.c shell_loop.c toolB.c env.c exe_cmd_g.c get_txt.c \
sig_g.c utils.c exe_line.c toolA.c

CC	= gcc
RM	= rm -rf
CFLAGS	= -I includes

ASTERISK_SRCS_PATH	= $(addprefix asterisk/,$(ASTERISK_SRCS))
BULITIN_SRCS_PATH	= $(addprefix bulitin/,$(BULITIN_SRCS))
ENVCL_SRCS_PATH		= $(addprefix envcl/,$(ENVCL_SRCS))
FIND_SRCS_PATH		= $(addprefix find/,$(FIND_SRCS))
GETCl_SRCS_PATH		= $(addprefix getcl/,$(GETCl_SRCS))
MKCMD_SRCS_PATH		= $(addprefix mkcmd/,$(MKCMD_SRCS))
LIBFT_PULUS_PATH	= $(addprefix libft_plus/,$(LIBFT_PULUS))
SRCS_PATH			= $(addprefix ./,$(SRCS))

ASTERISK_SRCS_OBJS	= $(ASTERISK_SRCS_PATH:.c=.o)
BULITIN_SRCS_OBJS	= $(BULITIN_SRCS_PATH:.c=.o)
ENVCL_SRCS_OBJS		= $(ENVCL_SRCS_PATH:.c=.o)
FIND_SRCS_OBJS		= $(FIND_SRCS_PATH:.c=.o)
GETCl_SRCS_OBJS		= $(GETCl_SRCS_PATH:.c=.o)
MKCMD_SRCS_OBJS		= $(MKCMD_SRCS_PATH:.c=.o)
LIBFT_PULUS_OBJS	= $(LIBFT_PULUS_PATH:.c=.o)
SRCS_OBJS			= $(SRCS_PATH:.c=.o)

OBJS += $(ASTERISK_SRCS_OBJS)
OBJS += $(BULITIN_SRCS_OBJS)
OBJS += $(ENVCL_SRCS_OBJS)
OBJS += $(FIND_SRCS_OBJS)
OBJS += $(GETCl_SRCS_OBJS)
OBJS += $(MKCMD_SRCS_OBJS)
OBJS += $(LIBFT_PULUS_OBJS)
OBJS += $(SRCS_OBJS)
OBJS += main.o

$(NAME)	: $(OBJS)
	gcc $(CFLAGS) $(OBJS) -o $(NAME) -L$(shell brew --prefix readline)/lib -lreadline 

%.o : %.c
	gcc $(CFLAGS) -c $< -o $@

main.o : main.c
	$(CC) $(CFRAGS) -c main.c

clean	: 
	$(RM) $(OBJS)

fclean	: clean
	$(RM) $(NAME)

re	: fclean all

.PHONY: all clean fclean re