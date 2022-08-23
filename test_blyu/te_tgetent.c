/* gcc te_tgetent.c -lcurses -ltermcap */
#include <termcap.h>
#include <string.h>
#include <stdlib.h>
#include "debug.h"

int main(int argc, char *argv[])
{
	TEST
	if (argc != 2)
		return 0;
	char buf[1024];
	bzero(buf, 1024);
	TESTn(tgetent(buf,argv[1]))
	TESTs(buf)
	return 0;
}

/* 
blyu@ryonoMacBook-Air test % gcc te_tgetent.c -lcurses -ltermcap
blyu@ryonoMacBook-Air test % ./a.out xxx                        
[(te_tgetent.c/7) main ]
[(te_tgetent.c/12) main ]tgetent(buf,argv[1]):-1
[(te_tgetent.c/13) main ]buf:
blyu@ryonoMacBook-Air test % ./a.out /xxx                       
[(te_tgetent.c/7) main ]
[(te_tgetent.c/12) main ]tgetent(buf,argv[1]):0
[(te_tgetent.c/13) main ]buf:
blyu@ryonoMacBook-Air test % ./a.out xterm-256color             
[(te_tgetent.c/7) main ]
[(te_tgetent.c/12) main ]tgetent(buf,argv[1]):1
[(te_tgetent.c/13) main ]buf:
blyu@ryonoMacBook-Air test % 
 */