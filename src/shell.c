#include "../include/shell.h"


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

// built-in commands execution"

void execute_command(Command_p cmd, char *file){

    if (strcmp(cmd->cmd, "exit")==0)
    {
        exit_cmd(cmd, file);
    }else if (strcmp("clear", cmd->cmd)==0)
    {
        screen_clear();
    }else if (strcmp("history", cmd->cmd)==0)
    {
        print_current_history(cmd);
    }else if (strcmp("session_back", cmd->cmd)==0)
    {
        print_content_history_file(file);
    }

} 

/*
 execute commandExternal commands 
 no pipe management and redirection
 manage &
*/

int extern_cmd(Command_p cmd){

        // check and execute command
    
    char **args = arg_build(cmd);

    if(strcmp(cmd->cmd, "\n") ){

        pid_t pid = fork();

        if (pid == -1) {
            perror("fork");
            return -1;
        } else if (pid == 0) {
            if(execvp(cmd->cmd, args)==-1){
            printf("commande incorrecte ou argument incorrecte\n");
            free(args);
            return -1;
            }

        }else {
            
            int wstatus;
            pid_t w;

            if(0){
                // mecanisme pour &
            }else{

                do {

                    
                    w = waitpid(pid, &wstatus, WUNTRACED | WCONTINUED);
                    if (w == -1) {
                        perror("waitpid");
                        free(args);
                        return -1;
                    }

                    if (WIFEXITED(wstatus)) {
                        printf("exited, status=%d\n", WEXITSTATUS(wstatus));
                    } else if (WIFSIGNALED(wstatus)) {
                        printf("killed by signal %d\n", WTERMSIG(wstatus));
                    } else if (WIFSTOPPED(wstatus)) {
                        printf("stopped by signal %d\n", WSTOPSIG(wstatus));
                    } else if (WIFCONTINUED(wstatus)) {
                        printf("continued\n");
                    }
                } while (!WIFEXITED(wstatus) && !WIFSIGNALED(wstatus));
            }
            
        }
            
    }
    free(args);
    return 0;
}
    
    
    


void exit_cmd(Command_p cmd, char *file){
    add_file(cmd, file);
	memfree(cmd);
    exit(EXIT_FAILURE);
}


void screen_clear(){
    printf("\033[H\033[J"); // ANSI code
}
