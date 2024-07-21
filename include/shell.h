#ifndef _SHELL_H_
#define _SHELL_H_

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../include/command.h"
#include<sys/wait.h>
#include<sys/types.h>
#include<stdint.h>
#include <unistd.h>


#define LEN_STDIN 30
#define TOK_LEN 30

void execute_command(Command_p cmd, char *file);
int extern_cmd(Command_p cmd);
void exit_cmd(Command_p cmd, char *file);
void screen_clear();
char **arg_build(Command_p cmd);
void redirect_stdin(Command_p cmd ,char *file);
void redirect_stdout(Command_p cmd, char *file);
void redirect_pipe(Command_p cmd);


#endif