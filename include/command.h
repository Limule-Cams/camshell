 #ifndef _COMMAND_H_
 #define _COMMAND_H_

 #include<stdlib.h>
 #include<stdio.h>
 #include<string.h>
 #define CMD_MAX 20


typedef enum bool
{
    false,
    true
}Bool;


typedef struct command{
    int nbre;
    char **args;
    char *cmd;
    int nb_arg;
    struct command *next
} Command_elm, *Command_p ;

Command_p _init_command();
Bool cmd_null(Command_p cmd);
void remove_last(Command_p cmd);
Command_p add_cmd(Command_p cmd, char *buff);
int count_cmd(Command_p cmd);


 #endif