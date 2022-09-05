#include "../minishell.h"
#include "getcl.h"

#include "../debug.h"

extern int	g_;

char	*getcl(void)
{
	char	*cl;
	char	*r;

	g_ = READING;
	cl = readline(PROMPT);
	if (!cl)
	{
		g_ = EXEING;
		return (NULL);
	}
	r = gcl_std(cl, 0);
	free(cl);
	g_ = EXEING;
	return (r);
}

/* 
int main(void)
{
    char *cl;
    t_cmd    *cmd;
	
	signal(SIGINT, sigint_handler);
    cl = getcl();
    while (cl)
    {
        add_history(cl);
		cl = etcl(cl);
		printf("-%s[\\n]\n", cl);
		free(cl);
        cl = getcl();
    }
    return 0;
}
 */