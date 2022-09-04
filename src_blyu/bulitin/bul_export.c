#include "../minishell.h"
#include "../debug.h"
//fd=2

void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);

int bul_export(int argc, char *argv[])
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
        {}
        else if (argv[i][ii] == '=')
        {
            argv[i][ii] = '\0';
            set_env(argv[i], argv[i] + ii + 1);
        }
        else
        {
            ft_putstr_fd("minishell: export: ", 2);
            ft_putstr_fd(argv[i], 2);
            ft_putchar_fd(' ', 2);
            ft_putstr_fd(": not a valid identifier\n", 2);
            //printf("minishell: export: `%s': not a valid identifier\n", argv[i]);
            r = 1;
        }
        i++;
    }	
    return(r);
}