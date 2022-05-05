#include "args.h"
#include <argp.h>
static struct argp_option options[] = {
    {"file", 'f', "FILE", 0, "Target file to watch"},
    {"dir", 'd', "DIR", 0, "Target directory to watch"},
};

static error_t parse_opt(int key, char *arg, struct argp_state *state) {
  struct arguments *arguments = state->input;
  switch (key) {
  case 'f':
    arguments->file = arg;
    break;
  case 'd':
    arguments->dir = arg;
    break;
  case ARGP_KEY_ARG:
    return 0;
  default:
    return ARGP_ERR_UNKNOWN;
  }
  return 0;
}

static struct argp argp = {options, parse_opt, 0, 0};

error_t conf2d_args(int argc, char **argv, struct arguments *args) {
  return argp_parse(&argp, argc, argv, 0, 0, args);
}
