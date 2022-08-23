#include <unistd.h>

//vim を開くことができる
int main (int argc, char *argv[])
{
	char *cmd[2] = {"vim", NULL};
	execve("/usr/bin/vim", cmd, NULL);
	return (0);
}

//これはcatコマンドを使ってmain.cっていうファイルをcat出来る
/* int main (int argc, char *argv[], char *envp[])
{
	char *cmd[3] = {"cat", "main.c", NULL};
	execve("/usr/bin/cat", cmd, NULL);
	return (0);
} */
//3つめの引数が いわゆるenvp で、"環境変数へのポインタ"らしい。 環境変数はbashやzshでいわゆる$PATHとかの事
//C言語のシステムコールで指定したプログラムを実行するexecve()
