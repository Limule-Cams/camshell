//parser

#include "../include/parser.h"

Command_p _init_command(){
    return NULL;
}

Bool cmd_null(Command_p cmd){

    if(cmd==NULL)
        return true ;

    return false;
}

//pop back
void remove_last(Command_p cmd){

    Command_elm *elm = cmd;
    Command_elm *prev = cmd;
    while (elm->next!=NULL)
    {
        prev = elm;
        elm = elm->next;
    }

    if (prev != NULL) {
        prev->next = NULL;
        free(elm->cmd);
        for (int i = 0; i < elm->nb_arg; i++) {
            free(elm->args[i]);
        }
        free(elm->args);
        free(elm);
    }
    
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

    // function that both parses and initializes the command structure

    Command_elm *elm;
    if((elm = malloc(sizeof(*elm)))==NULL){
        perror("malloc add_cmd");
        exit(EXIT_FAILURE);
    }
    //parsing with strtok 
    char delim[]=" ";
    char *token = strtok(buff, delim);
    if(token!=NULL){
        elm->cmd = strdup(token);
        elm->nb_arg = 0;

        //allocate memory for elm->args
        //it's a pointer to an array of strings
        elm->args = malloc(sizeof(char *));
        if (elm->args == NULL) {
            perror("malloc add_cmd");
            free(elm->cmd);
            free(elm);
            exit(EXIT_FAILURE);
        }
        //We allocate memory as many times as there are arguments
        while ((token = strtok(NULL, delim))!=NULL){
                elm->args = realloc(elm->args, (elm->nb_arg + 1) * sizeof(char *));
            if (elm->args == NULL) {
                perror("realloc add_cmd");
                free(elm->cmd);
                for (int i = 0; i < elm->nb_arg; i++) {
                    free(elm->args[i]);
                }
                free(elm->args);
                free(elm);
                exit(EXIT_FAILURE);
            }
            // init string
            elm->args[elm->nb_arg] = strdup(token);
            elm->nb_arg++;
        }
    }
    else{
        //token null error 
        free(elm);
        elm=NULL;
        perror("parse de commande erreur");
        exit(EXIT_FAILURE);
    }
    
    // if not command , elm=head of list
    if(cmd_null(cmd)){
        elm->next = cmd;
        return elm;
    }else{

        //if list=!NULL add elm 
        int count_elm = count_cmd(cmd);
        //check if count_elm=CMD_MAX (max number of orders in our list). if yes delete the last element and add new on the head
        // if not add new
        if((count_elm==CMD_MAX )){
            remove_last(cmd);     
        }

        elm->next = cmd;
        return elm;

    }
}



int memfree(Command_p cmd){

    // released everything that is in memory (Type Command_p)
    if(cmd_null(cmd)) return -1;
    while(cmd!=NULL){
        free(cmd->cmd);
        for(int i=0; i<cmd->nb_arg; i++){
            free(cmd->args[i]);
        }
        free(cmd->args);
        cmd = cmd->next;
    }
    free(cmd);
    return 0;
}


/*
this function constructs an array of args for execvp
if a cmd has no argument this array contains the name of the cmd and NULL
*/
char **arg_build(Command_p cmd){

    char **arg = malloc(sizeof(char *)*(cmd->nb_arg + 2));
    if(arg==NULL){
        perror("arg_build malloc fail");
        return NULL;
    }
    int i=0;
    arg[0] = cmd->cmd;
    if(cmd->nb_arg!=0){
        for(i=0; i<cmd->nb_arg; i++){
            arg[i+1]=cmd->args[i];
        }
    }
    arg[cmd->nb_arg + 1] = NULL;

    return arg;
}

//using in function extern_cmd for check mode execution processus : simple or with &
Bool check_execution_mode(char *buff){

    Bool exec_mode = true;
	if((strcspn(buff, "\n") - strcspn(buff, "&"))==1){
		buff[strcspn(buff, "&")] = '\0';
		exec_mode = false;
    }
    return exec_mode;
}