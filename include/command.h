 #ifndef _COMMAND_H_
 #define _COMMAND_H_

 #include<stdlib.h>
 #include<stdint.h>
 #define CMD_MAX 20


typedef struct bool
{
    false;
    true
}Bool;


typedef struct command{
    int nbre;
    char arg[10];
    char sub_arg;
    struct command *next
} Command_elm, *Command_p ;

Command_p _init_command();
Command_p add_cmd(Command_p cmd);
Bool cmd_null(Command_p cmd);
void remove_last(Command_p cmd);

 #endif