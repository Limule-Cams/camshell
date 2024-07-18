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
        fprintf(stdout, "erreur d'allocation elm");
        exit(EXIT_FAILURE);
    }
    //parsing with strtok 
    char delim[]=" ";
    char *token = strtok(buff, delim);
    if(token!=NULL){
        elm->cmd = strdup(token);
        elm->nb_arg = 0;

        elm->args = malloc(sizeof(char *));
        if (elm->args == NULL) {
            fprintf(stderr, "erreur d'allocation pour args\n");
            free(elm->cmd);
            free(elm);
            exit(EXIT_FAILURE);
        }

        while ((token = strtok(NULL, delim))!=NULL){
                elm->args = realloc(elm->args, (elm->nb_arg + 1) * sizeof(char *));
            if (elm->args == NULL) {
                fprintf(stderr, "erreur de réallocation pour args\n");
                free(elm->cmd);
                for (int i = 0; i < elm->nb_arg; i++) {
                    free(elm->args[i]);
                }
                free(elm->args);
                free(elm);
                exit(EXIT_FAILURE);
            }
            elm->args[elm->nb_arg] = strdup(token);
            elm->nb_arg++;
        }
    }
    else{
        free(elm);
        elm=NULL;
        perror("parse de commande erreur");
        exit(EXIT_FAILURE);
    }
    

    if(cmd_null(cmd)){
        elm->next = cmd;
        return elm;
    }else{

        // normalement count_cmd != 0
        int count_elm = count_cmd(cmd);

        if((count_elm==CMD_MAX )){
            remove_last(cmd);     
        }

        elm->next = cmd;
        return elm;

    }
}


void add_file(Command_p cmd, char *file){

    FILE *fic;
    fic = fopen(file, "a");
    if(fic==NULL) return;

    while(cmd!=NULL){

        fprintf(fic, "%s ", cmd->cmd);

        for(int i=0; i<cmd->nb_arg; i++){

            fprintf(fic, "%s ", cmd->args[i]);
        }
        fprintf(fic, "\n");
        cmd = cmd->next;
    }

    fclose(fic);

}

void print_content_history_file(char *file){

    FILE *fic;
    fic = fopen(file, "r");
    if(fic==NULL) return;

    char cmd[20];
    while (fgets(cmd, sizeof(cmd), fic) != NULL)
    {
        printf("%s", cmd);
    }
    fclose(fic);

}



void print_current_history(Command_p cmd){

    if(cmd==NULL){
        fprintf(stdout, "\nAucune commande pour la nouvelle session\nVeillez taper la commande back_history");
        return;
    }
    while(cmd!=NULL){
        printf("%s", cmd->cmd);
        for(int i=0; i<cmd->nb_arg;i++)
            printf(" %s ", cmd->args[i]);

        cmd = cmd->next;
        
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
