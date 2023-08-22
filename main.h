#ifndef HEADER_H
#define HEADER_H

/*Include helpful libraries for building the shell */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdbool.h>

/*Declare the global environment variable */
extern char **environ;

/*Function prototypes for the shell */
int _execute(char *full, char **line_arr);
void funny_shell(void);

int pathcmd_handler(char **line_arr);

void prompt_cmd(void);
char *read_cmdline(void);

int print_str(char *str);

void handle_signal(int sin);
char **line_to_tokens(char *line);

void full_env(char *line);

#endif
