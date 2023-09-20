#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

int _builtInCmd(char **arg);
char *location(char *path, char *arg);
int _printstring(char *str);
int _putchar(char c);
char *get_loc( char *arg);

#endif
