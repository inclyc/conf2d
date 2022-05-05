#include "args.h"
#include "clocker.h"
#include "dir2file.h"
#include "monitor.h"
#include <errno.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/inotify.h>
int main(int argc, char *argv[]) {
  struct arguments args;
  int len, i;
  conf2d_args(argc, argv, &args);
  pthread_t thread;
  pthread_create(&thread, NULL, clocker, &args);
  monitor(args.dir, args.file);
  pthread_join(thread, NULL);
}
