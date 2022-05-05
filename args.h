#ifndef ARGS_H
#define ARGS_H
#include <argp.h>
struct arguments {
  char *file;
  char *dir;
};

error_t conf2d_args(int argc, char *argv[], struct arguments *args);
#endif
