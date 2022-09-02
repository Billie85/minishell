#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"
#include <unistd.h>

typedef struct s_envp
{
	struct s_envp *next;
	char	*data;
} t_envp;

