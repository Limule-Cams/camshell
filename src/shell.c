#include "../include/shell.h"


void execute_command(Command_p cmd, char *file){

    if (strcmp(cmd->cmd, "exit")==0)
    {
        exit_cmd(cmd, file);
    }else if (strcmp("clear", cmd->cmd)==0)
    {
        clear_shell();
    }else if (strcmp("history", cmd->cmd)==0)
    {
        print_current_history(cmd);
    }else if (strcmp("session_back", cmd->cmd)==0)
    {
        print_content_history_file(file);
    }
    else{

        // check and execute command
        char *args[cmd->nb_arg +2];
        int i=0;
        args[0] = cmd->cmd;
        for(i=0; i<cmd->nb_arg; i++){
            args[i]=cmd->args[i];
        }


        // execute extern  command 
    }
    
    
    
}


void exit_cmd(Command_p cmd, char *file){
    add_file(cmd, file);
	memfree(cmd);
    exit(EXIT_FAILURE);
}


void clear_shell(){
    ;
}
