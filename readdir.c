#include <stdio.h>
#include <dirent.h>
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
