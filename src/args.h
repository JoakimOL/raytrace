#ifndef ARGS_H_
#define ARGS_H_ 

#include <getopt.h>
#include <stdio.h>

#define WIDTH  800
#define HEIGHT 600

int preview;
int verbose;
char* filename;

void parse_args( int argc, char *argv[]);
void print_usage();

#endif
