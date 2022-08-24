#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
//waitは、子プロセスの終了を待ち合わせるためのもの。
//wait が実行されなかった場合には、終了した子プロセスは 「ゾンビ」状態で残り続ける
//返り値 wait ():成功すると、終了した子プロセスのプロセスID を返す。 エラーの場合 -1 を返す。 

int main() {
    pid_t c_pid = fork();

    if (c_pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (c_pid == 0) {
        printf("printed from child process %d\n", getpid());
        exit(EXIT_SUCCESS);
    } else {
        printf("printed from parent process %d\n", getpid());
       wait(NULL);
    }

    exit(EXIT_SUCCESS);
}