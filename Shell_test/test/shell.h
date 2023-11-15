#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/types.h>

#define END_OF_FILE -2
#define EXIT -3

/*** Glbl hist cntr ***/
extern int hist;
/*** Glbl environemnt ***/
extern char **environ;
/*** Glbl program name ***/
extern char *name;

/**
 * struct list_s - struct type defining a linked list
 * @dir:  path to the directory
 * @nxt: pointer to another structured list_s
 *
 */

typedef struct list_s
{
	char *dir;
	struct list_s *nxt;
} list_t;

/**
 * struct builtin_s - struct type defining built-in commands
 * @i: pointer to the built-in command
 * @id: The name given to the built-in command
 *
 */

typedef struct builtin_s
{
	char *id;
	int (*i)(char **argv, char **front);
} builtin_t;

/**
 * struct alias_s - structured list defining alias_s
 * @val: value of the alias
 * @nme: name of the alias
 * @nxt: pointer to another structured list alias_s
 *
 */

typedef struct alias_s
{
	char *nme;
	char *val;
	struct alias_s *nxt;
} alias_t;

/* --Gbl alias_s linked_list --*/
alias_t *aliases;

/*** Input Helpers ***/
int run_args(char **args, char **front, int *exe_ret);
int handle_args(int *exe_ret);
int check_args(char **args);
void free_args(char **args, char **front);
char **replace_aliases(char **args);
void handle_line(char **line, ssize_t read);
void variable_replacement(char **args, int *exe_ret);
char *get_args(char *line, int *exe_ret);
int call_args(char **args, char **front, int *exe_ret);

/*** Main Helpers ***/
char **_strtok(char *line, char *delim);
char *get_location(char *command);
list_t *get_path_dir(char *path);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
int execute(char **args, char **front);
void free_list(list_t *head);
char *_itoa(int num);

/*** Built-in Helpers ***/
char **_getenv(const char *var);
char **_copyenv(void);
void free_env(void);

/*** Built-ins ***/

int shellby_unsetenv(char **args, char __attribute__((__unused__)) **front);
int shellby_cd(char **args, char __attribute__((__unused__)) **front);
int shellby_alias(char **args, char __attribute__((__unused__)) **front);
int shellby_help(char **args, char __attribute__((__unused__)) **front);
int (*get_builtin(char *command))(char **args, char **front);
int shellby_exit(char **args, char **front);
int shellby_env(char **args, char __attribute__((__unused__)) **front);
int shellby_setenv(char **args, char __attribute__((__unused__)) **front);

/*** Linked-list Helpers ***/

list_t *add_node_end(list_t **head, char *dir);
alias_t *add_alias_end(alias_t **head, char *name, char *value);
void free_alias_list(alias_t *head);
void free_list(list_t *head);

void help_all(void);
void help_alias(void);
void help_cd(void);
void help_exit(void);
void help_help(void);
void help_env(void);
void help_setenv(void);
void help_unsetenv(void);
void help_history(void);

/*** Error Handler ***/

char *error_1(char **args);
char *error_2_exit(char **args);
char *error_2_cd(char **args);
char *error_2_syntax(char **args);
char *error_126(char **args);
char *error_127(char **args);
int create_error(char **args, int err);
char *error_env(char **args);

int proc_file_commands(char *file_path, int *exe_ret);

#endif /** SHELL_H_ **/
