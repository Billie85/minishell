#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int
main(int argc, char *argv[])
{
    struct stat sb;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <pathname>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if (stat(argv[1], &sb) == -1) {
        perror("stat");
        exit(EXIT_FAILURE);
    }

    printf("File type:                ");

    switch (sb.st_mode & S_IFMT) {
    case S_IFBLK:  printf("block device\n");            break;
    case S_IFCHR:  printf("character device\n");        break;
    case S_IFDIR:  printf("directory\n");               break;
    case S_IFIFO:  printf("FIFO/pipe\n");               break;
    case S_IFLNK:  printf("symlink\n");                 break;
    case S_IFREG:  printf("regular file\n");            break;
    case S_IFSOCK: printf("socket\n");                  break;
    default:       printf("unknown?\n");                break;
    }

    printf("I-node number:            %ld\n", (long) sb.st_ino);

    printf("Mode:                     %lo (octal)\n",
            (unsigned long) sb.st_mode);

    printf("Link count:               %ld\n", (long) sb.st_nlink);
    printf("Ownership:                UID=%ld   GID=%ld\n",
            (long) sb.st_uid, (long) sb.st_gid);

    printf("Preferred I/O block size: %ld bytes\n",
            (long) sb.st_blksize);
    printf("File size:                %lld bytes\n",
            (long long) sb.st_size);
    printf("Blocks allocated:         %lld\n",
            (long long) sb.st_blocks);

    printf("Last status change:       %s", ctime(&sb.st_ctime));
    printf("Last file access:         %s", ctime(&sb.st_atime));
    printf("Last file modification:   %s", ctime(&sb.st_mtime));

    exit(EXIT_SUCCESS);
}
//struct stat {
//    dev_t     st_dev;     /* ファイルがあるデバイスの ID */
//    ino_t     st_ino;     /* inode 番号 */ //->inode:ファイルに関するデータ
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

