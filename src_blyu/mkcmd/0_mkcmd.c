#include "../minishell.h"
#include "mkcmd.h"

#include "../debug.h"

//tk_stdはデフォルト、ファイル名取得のときのみ使う/* 訂正 */
//構文のエラーのときは c->type = SYNTAXERROR を設定/* 訂正 */


char	*mkcmd(t_cmd *c, char *cl)
{
	char	*ncl;

//TESTs(cl)
	c->cmd = cmdlist(c, cl, &ncl, 0);
	if (!(c->cmd) && c->n_type != SYNTAXERROR)
		return (NULL);
	if (c->n_type == SYNTAXERROR)
		ncl = cl + strlen(cl);
	return (ncl);
}
