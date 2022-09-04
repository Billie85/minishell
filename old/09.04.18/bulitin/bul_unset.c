#include "../minishell.h"
#include "../debug.h"
//fd=2

int bul_unset(int argc, char *argv[])
{
    size_t i;
    size_t ii;
    int r;

    r = 0;
    i = 1;
    while(i < argc)
    {
        ii = 0;
        while (isalpha(argv[i][ii]))
            ii++;
        if (argv[i][ii] == '\0')
        {
            rm_env(argv[i]);
        }
        else
        {
            printf("minishell: unset: `%s': not a valid identifier\n", argv[i]);
            r = 1;
        }
        i++;
    }	
    return(r);
}