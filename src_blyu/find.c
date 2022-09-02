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
#include "minishell.h"
#include "debug.h"

typedef struct s_dirs
{
	DIR				*dir;
	char			*str;
	struct s_dirs	*befor;
}	t_dirs;

char    **fi_std(t_dirs *d, size_t dw);

char	**find(char *search)
{
	char	c;
	size_t	i;
	t_dirs	d;
	char	**r;

	i = strlen(search);
	while (i && search[i] != '/')
		i--;
	if (search[i] == '/')
	{
		c = search[i + 1];
		search[i + 1] = '\0';
		d.dir = opendir(search);
TESTp(d.dir)
		if (!(d.dir))
		{
			r = malloc(sizeof(char **));
			if (!r)
			{
				printf("malloc error\n");
				return (NULL);
			}
			*r = NULL;
			return (r);
		}
		d.str = search;
		d.befor = NULL;
		r = fi_std(&d, 0);
		search[i + 1] = c;
		if (!r)
			return (NULL);
	}
	else
	{
		d.dir = opendir("./");
		if (!(d.dir))
		{
			r = malloc(sizeof(char **));
			if (!r)
			{
				printf("malloc error\n");
				return (NULL);
			}
			*r = NULL;
			return (r);
		}
		d.str = "./";
		d.befor = NULL;
		r = fi_std(&d, 0);
		if (!r)
			return (NULL);
		size_t	ii = 0;
		while (r[ii])
		{
			memmove(r[ii], r[ii] + 2, strlen(r[ii] + 2) + 1);/*  */
			ii++;
		}
	}
	i = 0;
	size_t	ii = 0;
	size_t	l = strlen(search);
	while (r[i])
	{
		if (strncmp(r[i], search, l))
			free(r[i]);
		else
		{
			r[ii] = r[i];
			memmove(r[ii], r[ii] + l, strlen(r[ii]) + 1);
			ii++;
		}
		i++;
	}
	r[ii] = NULL;
	return (r);
}


char    **fi_std(t_dirs *d, size_t dw)
{
	t_dirs	nd;
	char	**r;
	char	*s;
	struct dirent *dent;

	if (!d)
	{
		r = malloc((dw + 1) * sizeof(char **));
		if (!r)
		{
			printf("malloc error\n");
			return (NULL);
		}
		return (r);
	}
	dent = readdir(d->dir);
	if(!dent)
	{
		closedir(d->dir);
		return (fi_std(d->befor, dw));
	}
	if (!strcmp(dent->d_name, ".."))
		return (fi_std(d, dw));
	else if (dent->d_type != DT_DIR || !strcmp(dent->d_name, "."))
	{
		s = ft_strjoin(d->str, dent->d_name);
		if (!s)
		{
			printf("malloc error\n");
			return (NULL);
		}
		r = fi_std(d, dw + 1);
		if (!r)
			return (NULL);
		r[dw] = s;
		return (r);
	}
	if (!strcmp(dent->d_name, ".."))
{
		return (fi_std(d, dw));
}
	else
	{
		size_t	i;
		size_t	ii;

		i = strlen(d->str);
		ii = strlen(dent->d_name);
		s = malloc(i + ii + 2);
		if (!s)
		{
			printf("malloc error\n");
			return (NULL);
		}
		memcpy(s, d->str, i);
		memcpy(s + i, dent->d_name, ii);
		s[i + ii] = '/';
		s[i + ii + 1] = '\0';
		nd.befor = d;
		nd.str = s;
		nd.dir = opendir(s);
		r = fi_std(&nd, dw);
		free(nd.str);
		return (r);
	}
}
/* 
int main(int argc, char *argv[]) {

	if (argc <= 1)
		return (0);
	char	**t = find(argv[1]);	
	for (size_t i = 0; t[i]; i++)
	{
		printf("%zu\t:%s[\\n]\n", i, t[i]);
	}
	return 0;
}
 */