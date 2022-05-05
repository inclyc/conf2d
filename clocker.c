#include "clocker.h"
#include "args.h"
#include "dir2file.h"
#include <unistd.h>
void *clocker(void *args) {
  struct arguments *arguments = (struct arguments *)args;
  const char *dirpath = arguments->dir;
  const char *filepath = arguments->file;
  for (;;) {
    dir2file(dirpath, filepath);
    sleep(SLEEP_SECOND);
  }
}
