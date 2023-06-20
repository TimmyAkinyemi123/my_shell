#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <dirent.h>

int _strcmp(char *s1, char *s2);
size_t _strcspn(char *str, char *charset);
char *read_line();
int parse_input(char *line);
int check_exec(char *line);
void exec_command(char *line);
void print_error();
int is_eof();
void handle_eof();
void shell_loop();

#endif
