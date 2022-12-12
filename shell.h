#ifndef SHELL_H_
#define SHELL_H_

#include <errno.h>
#include <fcntl.h>
#include <limits.h>
#include <signal.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define BUFSIZE 1024
#define NEWLINE '\n'
#define DELIM_T " \t\n\a\r"

extern char **environ;

/**
 * struct path - path variable
 * @str: string
 * @next: next
 *
 */
typedef struct path
{
	char *str;
	struct path *next;
} path_l;

/**
 * struct com_mand - structure containing command argument types
 * @str: string
 * @next: next
 *
 */
typedef struct com_mand
{
	char **arr;
} com_mand;

/**
 * struct built_in - path variable
 * @str: string
 * @next: next
 *
 */
typedef struct built_in
{
	char *str;
	int (*func)(com_mand);
} built_in;




char **get_commands(char *, size_t);
char *_getenv(const char *);
char *my_strcat(char *, char *);
char *my_strcpy(char *, char *);
char *my_strdup(char *);
char *my_strtok(char *, const char *);
int my_isdigit(char *);
int (*get_func(char *))(com_mand);
int my_strcmp(char *, char *);
int my_strlen(char *);
path_l *add_node_end(path_l **, const char *);
path_l *path_to_list(void);
size_t print_list(const path_l *);
ssize_t my_getline(char **, size_t *, FILE *);
void *my_memchr(register const void *, int, size_t);
void free_arr2(char **);
void free_list(path_l *);
void get_signal(int);
void insert_line(char **, size_t *n, char *, size_t);
void my_memcpy(void *, const void *, unsigned int);
void *my_realloc(void *, unsigned int, unsigned int);
void print_path_dir(void);
void reverse_str(char *);

#endif
