#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

extern char **environ;

ssize_t my_getline(char **lineptr, size_t *size, FILE *file);
char *my_strtok(char *str, const char *delim);
void print(void);
void execute_ls(void);

#endif /* MAIN_H */
