#include "dir2file.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/inotify.h>
#include <unistd.h>
void monitor(const char *dirpath, const char *filepath) {
  static char buf[4096];
  const struct inotify_event *event;
  int inot_fd = inotify_init();
  int inot_wd =
      inotify_add_watch(inot_fd, dirpath, IN_MODIFY | IN_CREATE | IN_DELETE);
  for (;;) {
    int len = read(inot_fd, buf, sizeof(buf));
    if (len < 0) {
      perror("read");
      exit(EXIT_FAILURE);
    }
    for (char *ptr = buf; ptr < buf + len;
         ptr += sizeof(struct inotify_event) + event->len) {
      event = (const struct inotify_event *)ptr;
      printf("Detect changes on %s\n", event->name);
      dir2file(dirpath, filepath);
    }
  }
}
