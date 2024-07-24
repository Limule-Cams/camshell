//user session

#include"../include/session.h"

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