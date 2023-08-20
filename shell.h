#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

#define BUFFER_SIZE 1024

extern char **environ;

int _putchar(char c);
char *_strcat(char *dest, char *src);
int _strlen(char *s);
char *_strcpy(char *dest, const char *src);
void execmd(char **argv);
char *get_location(char *command);
char *strdup(const char *s);
int main(int ac, char **argv);
char *own_getline();

#endif
