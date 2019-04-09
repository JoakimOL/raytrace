#ifndef ARGS_H_
#define ARGS_H_ 

#include <getopt.h>
#include <stdio.h>

int preview;
int verbose;
char* filename;

void parse_args( int argc, char *argv[]);
void print_usage();

#endif
