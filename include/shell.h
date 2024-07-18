#ifndef _SHELL_H_
#define _SHELL_H_

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../include/command.h"

#define LEN_STDIN 30
#define TOK_LEN 30

void execute_command(Command_p cmd, char *file);
void exit_cmd();
void clear_shell();

void redirect_stdin(Command_p cmd ,char *file);
void redirect_stdout(Command_p cmd, char *file);
void redirect_pipe(Command_p cmd);


#endif