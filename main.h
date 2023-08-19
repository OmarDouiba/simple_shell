#ifndef HEADER_H
#define HEADER_H

/* Include helpful libraries for building the shell */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include<fcntl.h>
#include <stdbool.h>

/* Declare the global environment variable */
extern char **environ;

/* Function prototypes for the shell */
int _execute(char *full, char **line_arr);
void funny_shell(void);

int checker(char **line_arr, char **path_arr);
int nan_exist_cmd(char **path_arr, char **line_arr);
int pathcmd_handler(char **line_arr);
char *concat_line_path(char *line_arr, char **path_arr);

void prompt_cmd(void);
char *read_cmdline(char *path_name, char **path_arr);

char **split_path(char *p_name);
int print_str(char *str);

void handle_signal(int sin);
char **line_to_tokens(char *line);

char *get_env(char *str);
void full_env(char *line);


bool true_false(const char *str, int i);
bool true_false2(char **line_arr);

#endif
