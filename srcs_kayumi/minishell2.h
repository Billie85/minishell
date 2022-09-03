#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libft/libft.h"
#include <unistd.h>
#include <stdbool.h>

typedef struct s_envp
{
	struct s_envp	*next;
	char			*content;
	char			*name;
}			t_envp;

int	get_envp(char *up_to_equal, char *envp[], char *after_equal);