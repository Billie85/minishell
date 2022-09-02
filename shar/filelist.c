// '/' './' '~/' から始まるものを識別

//それ以外はカレントディレクトリのものを調べる

//引数で指定した先を返す
//ex)引数:"/abc/hello"
//見つかったもの:/abc/hello_world.txt, /abc/hello_d/text.txt, /abc/hello
//return_value[0] = "_world.txt\0"
//return_value[1] = "_d/text.txt\0"
//return_value[2] = "\0"
//return_value[3] = NULL

//存在しない場合は最初の最初の要素にmallocで確保した場所にNULLを入れる(つまり、mallocエラーのときのみNULLを返す)
//return_value[0] = NULL<-存在しない場合
//retuen(return_value);
//retuen(NULL); <-mallocエラーの場合
char    **find(const char *search)
{
    
}

int main(int argc, char**argv) {
  char *path = "./";
  DIR *dir;
  struct dirent *dent;
  if (argc > 1) {
    path = argv[1];
  }
  dir = opendir(path);
  if (dir == NULL) {
    perror(path);
    return 1;
  }
  while ((dent = readdir(dir)) != NULL) {
    printf("%s\n", dent->d_name);
  }
  closedir(dir);
  return 0;
}
