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
    prev->next = NULL;
    free(elm);
    elm = NULL;
}



int count_cmd(Command_p cmd){
    int nbre = 0;
    while(cmd!= NULL){
        nbre++;
        cmd = cmd->next;
    }
    return nbre;
}



Command_p add_cmd(Command_p cmd, char *buff){

    Command_elm *elm;
    if(elm = malloc(sizeof(*elm))==NULL){
        fprintf(stdout, "erreur d'allocation");
        exit(EXIT_FAILURE);
    }

    /*
    parser l'entrée qui est la chaine buff
    on utilise strtok pour diviser son contenu en une commande elm->cmd
    ses argument elm->args
    et on compte son nbre d'argument avec elm->nb_arg
    */

    char delim[]=" ";
    char *token = strtok(buff, delim);
    if(token!=NULL)
        elm->cmd = strdup(token);
    else{
        free(elm);
        perror("parse de commande erreur");
        exit(EXIT_FAILURE);
    }
    elm->nb_arg = 0;
    while ((token = strtok(NULL, delim))!=NULL)
    {
        elm->args[elm->nb_arg] = strdup(token);
        elm->nb_arg++;
    }
    


    if(cmd_null(cmd)){
        elm->next = cmd;
        return elm;
    }else{

        int count_elm = count_cmd(cmd);
        if(count_elm==CMD_MAX){

            remove_last(cmd);
            elm->next = cmd;
            return elm;
            
        }else{
            elm->next = cmd;
            return elm;
        }
    }
}


