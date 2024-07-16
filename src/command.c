#include "../include/command.h"

Command_p _init_command(){
    
    return NULL;
}

Bool cmd_null(Command_p cmd){

    if(cmd==NULL)
        return true ;
    return false;
}

void remove_last(Command_p cmd){

    Command_elm *elm = cmd;
    Command_elm *prev = cmd;
    while (elm->next!=NULL)
    {
        prev = elm;
        elm = elm->next;
    }
    prev->next = NULL
    free(elm);
    elm = NULL;
}

Command_p add_cmd(Command_p cmd){

    Command_elm *elm;
    if(elm = malloc(sizeof(*elm))==NULL){
        fprintf(stdout, "erreur d'allocation");
        exit(EXIT_FAILURE);
    }

    /*
    init membre of struct
    use strtok for write in elm->arg, elm->sub_arg, 
    elm->nbre for count the nbre elm in our list of command +=1 
    */


    if(cmd_null(cmd)){
        elm->next = cmd;
        return elm;
    }else{
        if(cmd->nbre==CMD_MAX){

            remove_last(cmd);
            elm->next = cmd;
            return elm;
            
        }else{
            elm->next = cmd;
            return elm;
        }
    }
}