#include "../minishell_bonus.h"
#include "getcl_bonus.h"

extern t_g	g_;

char	*getcl(void)
{
	char	*cl;
	char	*r;

	g_.status = READING;
	cl = readline(PROMPT);
	if (!cl)
	{
		g_.status = EXEING;
		return (NULL);
	}
	r = gcl_std(cl, 0);
	free(cl);
	g_.status = EXEING;
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
