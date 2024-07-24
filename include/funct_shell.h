#ifndef __FUNCT_SHELL__H__
#define __FUNCT_SHELL__H__

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../include/parser.h"
#include<sys/wait.h>
#include<sys/types.h>
#include<stdint.h>
#include <unistd.h>



#define LEN_STDIN 30
#define TOK_LEN 30

void execute_command(Command_p cmd, char *file);
int extern_cmd(Command_p cmd, Bool mode_exec);
void exit_cmd(Command_p cmd, char *file);
void screen_clear();

int change_directory(Command_p cmd);
char *print_working_directory();




#endif