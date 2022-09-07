NAME	= minishell

ASTERISK_SRCS	= 0_asterisk.c as_as_list.c as_as_q.c as_as_std.c as_stdA.c as_stdB.c

BULITIN_SRCS	= bul_cd.c bul_echo.c bul_env.c bul_export.c bul_pwd.c bul_unset.c

ENVCL_SRCS		= 0_envcl.c ecl_env_dq.c ecl_sp.c ecl_stdA.c ecl_dq.c ecl_env_std.c ecl_sq.c ecl_stdB.c extractenv.c

FIND_SRCS		= 0_find.c fi_dir.c fi_list.c fi_ok.c fi_std.c

GETCl_SRCS		= 0_getcl_g.c gcl_dq.c gcl_nc.c gcl_sq.c gcl_stdA.c gcl_stdB.c

MKCMD_SRCS		= 0_mkcmd.c cmdlistB.c tk_ques_g.c tk_stdA.c cmdlistA.c cmdlistC.c tk_dq.c tk_sq.c tk_stdB.c

LIBFT_PULUS		= ft_strcmp.c ft_strstr.c

SRCS			= main.c exe_bulitin_g.c shell_loop.c toolB.c env.c exe_cmd_g.c get_txt.c utils.c exe_line_g.c toolA.c
######################################################################################################################
NAMEb	= minishell_bonus

ASTERISK_SRCSb	= 0_asterisk_bonus.c as_as_list_bonus.c as_as_q_bonus.c as_as_std_bonus.c as_stdA_bonus.c as_stdB_bonus.c

BULITIN_SRCSb	= bul_cd_bonus.c bul_echo_bonus.c bul_env_bonus.c bul_export_bonus.c bul_pwd_bonus.c bul_unset_bonus.c

ENVCL_SRCSb		= 0_envcl_bonus.c ecl_env_dq_bonus.c ecl_sp_bonus.c ecl_stdA_bonus.c ecl_dq_bonus.c ecl_env_std_bonus.c ecl_sq_bonus.c ecl_stdB_bonus.c extractenv_bonus.c

FIND_SRCSb		= 0_find_bonus.c fi_dir_bonus.c fi_list_bonus.c fi_ok_bonus.c fi_std_bonus.c

GETCl_SRCSb		= 0_getcl_g_bonus.c gcl_dq_bonus.c gcl_nc_bonus.c gcl_sq_bonus.c gcl_stdA_bonus.c gcl_stdB_bonus.c

MKCMD_SRCSb		= 0_mkcmd_bonus.c cmdlistB_bonus.c tk_ques_g_bonus.c tk_stdA_bonus.c cmdlistA_bonus.c cmdlistC_bonus.c tk_dq_bonus.c tk_sq_bonus.c tk_stdB_bonus.c

LIBFT_PULUSb	= ft_strcmp_bonus.c ft_strstr_bonus.c

SRCSb			= main_bonus.c exe_bulitin_g_bonus.c shell_loop_bonus.c toolB_bonus.c env_bonus.c exe_cmd_g_bonus.c get_txt_bonus.c utils_bonus.c exe_line_g_bonus.c toolA_bonus.c


LIBFT_dir		= libft/
LIBFT_a			= libft.a

CC	= cc
RM	= rm -rf
CFLAGS	= -Wall -Wextra -Werror

ASTERISK_SRCS_PATH	= $(addprefix asterisk/,$(ASTERISK_SRCS))
BULITIN_SRCS_PATH	= $(addprefix bulitin/,$(BULITIN_SRCS))
ENVCL_SRCS_PATH		= $(addprefix envcl/,$(ENVCL_SRCS))
FIND_SRCS_PATH		= $(addprefix find/,$(FIND_SRCS))
GETCl_SRCS_PATH		= $(addprefix getcl/,$(GETCl_SRCS))
MKCMD_SRCS_PATH		= $(addprefix mkcmd/,$(MKCMD_SRCS))
LIBFT_PULUS_PATH	= $(addprefix libft_plus/,$(LIBFT_PULUS))
SRCS_PATH			= $(addprefix ./,$(SRCS))
LIBFT_PATH			= $(LIBFT_dir)$(LIBFT_a)

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
OBJS += sig_g.o

ASTERISK_SRCS_PATHb	= $(addprefix asterisk_bonus/,$(ASTERISK_SRCSb))
BULITIN_SRCS_PATHb	= $(addprefix bulitin_bonus/,$(BULITIN_SRCSb))
ENVCL_SRCS_PATHb	= $(addprefix envcl_bonus/,$(ENVCL_SRCSb))
FIND_SRCS_PATHb		= $(addprefix find_bonus/,$(FIND_SRCSb))
GETCl_SRCS_PATHb	= $(addprefix getcl_bonus/,$(GETCl_SRCSb))
MKCMD_SRCS_PATHb	= $(addprefix mkcmd_bonus/,$(MKCMD_SRCSb))
LIBFT_PULUS_PATHb	= $(addprefix libft_plus_bonus/,$(LIBFT_PULUSb))
SRCS_PATHb			= $(addprefix ./,$(SRCSb))

ASTERISK_SRCS_OBJSb	= $(ASTERISK_SRCS_PATHb:.c=.o)
BULITIN_SRCS_OBJSb	= $(BULITIN_SRCS_PATHb:.c=.o)
ENVCL_SRCS_OBJSb	= $(ENVCL_SRCS_PATHb:.c=.o)
FIND_SRCS_OBJSb		= $(FIND_SRCS_PATHb:.c=.o)
GETCl_SRCS_OBJSb	= $(GETCl_SRCS_PATHb:.c=.o)
MKCMD_SRCS_OBJSb	= $(MKCMD_SRCS_PATHb:.c=.o)
LIBFT_PULUS_OBJSb	= $(LIBFT_PULUS_PATHb:.c=.o)
SRCS_OBJSb			= $(SRCS_PATHb:.c=.o)

OBJSb += $(ASTERISK_SRCS_OBJSb)
OBJSb += $(BULITIN_SRCS_OBJSb)
OBJSb += $(ENVCL_SRCS_OBJSb)
OBJSb += $(FIND_SRCS_OBJSb)
OBJSb += $(GETCl_SRCS_OBJSb)
OBJSb += $(MKCMD_SRCS_OBJSb)
OBJSb += $(LIBFT_PULUS_OBJSb)
OBJSb += $(SRCS_OBJSb)
OBJSb += sig_g_bonus.o

all : $(NAME)

bonus : $(NAMEb)

$(NAME)	: $(OBJS) $(LIBFT_a)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_a) -o $(NAME) -L$(shell brew --prefix readline)/lib  -lreadline

$(NAMEb) : $(OBJSb) $(LIBFT_a)
	$(CC) $(CFLAGS) $(OBJSb) $(LIBFT_a) -o $(NAMEb) -L$(shell brew --prefix readline)/lib  -lreadline

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

sig_g.o : sig_g.c
	$(CC) $(CFLAGS) -c $< -o $@ -I$(shell brew --prefix readline)/include

sig_g_bonus.o : sig_g_bonus.c
	$(CC) $(CFLAGS) -c $< -o $@ -I$(shell brew --prefix readline)/include

$(LIBFT_a) : 
	cd "$(LIBFT_dir)" && make bonus
	cp $(LIBFT_PATH) ./

clean	: 
	$(RM) $(OBJS)
	$(RM) $(OBJSb)
	$(RM) $(LIBFT_a)
	cd "$(LIBFT_dir)" && make fclean

fclean	: clean
	$(RM) $(NAME)
	$(RM) $(NAMEb)
	
re	: fclean all

.PHONY: all clean fclean re