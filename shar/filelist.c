// '/' './' '~/' から始まるものを識別

//それ以外はカレントディレクトリのものを調べる

//引数で指定した先を返す
//ex)引数:"/abc/hello"
//見つかったもの:/abc/hello_world.txt, /abc/hello_d/text.txt, /abc/hello
//return_value[0] = "_world.txt\0"
//return_value[1] = "_d/text.txt\0"
//return_value[2] = "\0"
//return_value[3] = NULL

//存在しない場合は最初の最初の要素にmallocで確保した"\0"を入れる(つまり、mallocエラーのときのみNULLを返す)

char    **find(const char *search)
{

}