#include "args.h"
#include "read_dir.h"
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/inotify.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  struct arguments args;
  int inot_fd; /* File descriptor for inotify */
  int inot_wd; /* Watch descriptor for the target file */
  int len, i;
  static char buf[4096];
  const struct inotify_event *event;

  parse_args(argc, argv, &args);

  inot_fd = inotify_init();

  inot_wd =
      inotify_add_watch(inot_fd, args.dir, IN_MODIFY | IN_CREATE | IN_DELETE);
  for (;;) {
    len = read(inot_fd, buf, sizeof(buf));
    if (len < 0) {
      perror("read");
      exit(EXIT_FAILURE);
    }
    for (char *ptr = buf; ptr < buf + len;
         ptr += sizeof(struct inotify_event) + event->len) {
      /* Get the event structure */
      event = (const struct inotify_event *)ptr;
      printf("%s\n", event->name);
      dir2file(args.dir, args.file);
    }
  }
}
