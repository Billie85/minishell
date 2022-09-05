//waitpid() システムコールは、 pid 引数で指定した子プロセスの状態変化が起こるまで、 呼び出し元のスレッドの実行を一時停止する。デフォルトでは、 
//waitpid() は子プロセスの終了だけを待つが、この動作は options 引数により変更可能である。
//成功すると、状態が変化した子プロセスのプロセスID を返す。 WNOHANG が指定されていて、 pid で指示された子プロセスが一つ以上存在するが、どの子プロセスでも 状態変化が起こっていなかった場合は、 0 を返す。 
//エラーの場合 -1 を返す。
//wait システムコールには複数の制限があり、より高度な機能をカバーするためには 
//waitpid 関数を利用する必要があります。すなわち、プロセスが複数の子プロセスを生成し、
//親が特定の子プロセスを監視する必要がある場合、waitpid だけがこれを行うことができます。

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

//wait3(status, options, rusage)
//waitpid(-1, status, option)

//wait4(pid, status, options, rusage)
//waitpid(pid, status, options)

/* pid_t wait3(int *status, int options,
		   struct rusage *rusage);

       pid_t wait4(pid_t pid, int *status, int options,
		   struct rusage *rusage); */

int main ( )
{
    int pid;
    int status;

    printf("Parent: %d\n", getpid());

    pid = fork();
    if (pid == 0)
	{
        printf("Child %d\n", getpid());
        sleep(2);
        exit(EXIT_SUCCESS);
    }
    wait4(pid, &status, 0, 0);//どっちでも行ける
	//waitpid(pid, &status, 0);
    printf("Parent: %d\n", getpid());

    return 0;
}