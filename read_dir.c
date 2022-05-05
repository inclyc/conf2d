#define _DEFAULT_SOURCE
#include "read_dir.h"
#include <dirent.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int dir2file(const char *dirpath, const char *filepath) {
  struct dirent **namelist;
  static char buf[1024];
  static char path_buf[1024];
  int fd = open(filepath, O_WRONLY);
  if (fd < 0) {
    perror("open");
    return -1;
  }
  int n = scandir(dirpath, &namelist, 0, alphasort);
  if (n < 0) {
    perror("scandir");
    return -1;
  }

  for (int i = 0; i < n; i++) {
    sprintf(path_buf, "%s/%s", dirpath, namelist[i]->d_name);
    printf("%s\n", path_buf);
    if (namelist[i]->d_type == DT_REG) {
      int fdo = open(path_buf, O_RDONLY);
      if (fdo < 0) {
        perror("open");
        return -1;
      }
      for (int n = 0;;) {
        n = read(fdo, buf, sizeof(buf));
        if (n < 0) {
          perror("read");
          return -1;
        } else if (n == 0) {
          break;
        }
        n = write(fd, buf, n);
        if (n < 0) {
          perror("write");
          return -1;
        }
      }
      close(fdo);
    }
    free(namelist[i]);
  }
  close(fd);
  return 0;
}
