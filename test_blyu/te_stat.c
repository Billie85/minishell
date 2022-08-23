#include <sys/stat.h>
#include <string.h>
#include "debug.h"

void    ls_l(struct stat *i)
{
    if ()
}

int main (int argc, int *argv[])
{
    struct stat buf = {0};
    TESTn(stat(argv[1], &buf))
    ls_l(&buf);

}

//struct stat {
//    dev_t     st_dev;     /* ファイルがあるデバイスの ID */
//    ino_t     st_ino;     /* inode 番号 */
//    mode_t    st_mode;    /* アクセス保護 */
//    nlink_t   st_nlink;   /* ハードリンクの数 */
//    uid_t     st_uid;     /* 所有者のユーザー ID */
//    gid_t     st_gid;     /* 所有者のグループ ID */
//    dev_t     st_rdev;    /* デバイス ID (特殊ファイルの場合) */
//    off_t     st_size;    /* 全体のサイズ (バイト単位) */
//    blksize_t st_blksize; /* ファイルシステム I/O での
//                             ブロックサイズ */
//    blkcnt_t  st_blocks;  /* 割り当てられた 512B のブロック数 */
//};