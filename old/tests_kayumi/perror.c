#include <stdio.h>

int main(void) {
    FILE *fp;
    fp = fopen("test3.txt", "r");
    
    if (fp == NULL) {
        perror("エラーが発生しました");
        return 0;
    } else {
        printf("ファイルが開きました");
    }

    fclose(fp);
    return 0;
}