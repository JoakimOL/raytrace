#ifndef ARGS_H_
#define ARGS_H_ 

#include <getopt.h>
#include <stdio.h>

static int preview;
static int verbose;
char* filename;

void parse_args( int argc, char *argv[]);
void print_usage();

#endif
