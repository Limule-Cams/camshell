//functions building and exec extern command 

#include "../include/funct_shell.h"




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
    }else if (strcmp("cd", cmd->cmd)==0)
    {
        change_directory(cmd);
    }
    else if (strcmp("pwd", cmd->cmd)==0)
    {
        if(cmd->nb_arg!=0){
            printf("la fonction s'utilise sans argument\n");
            exit_cmd(cmd, file);
        }else{
            char *dir = print_working_directory();
            if(dir!=NULL){
                printf("%s\n", dir);
                free(dir);
            }
        }

    }else if (strcmp("show", cmd->cmd)==0)
    {
        if(cmd->nb_arg==2){
            if(strcmp("-e", cmd->args[0])==0)
                print_var(cmd->args[1]);
        }else
            printf(" nombre d'argument incorrecte\n");
    }
    else if (strcmp("all_var", cmd->cmd)==0)
    {
        show_env_vars();
    }else if (strcmp("export", cmd->cmd)==0)
    {
        
    }
    
    
    

} 

/*
 execute commandExternal commands 
 no pipe not redirection
 but manage &
*/

int extern_cmd(Command_p cmd, Bool mode_exec){

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

            if(mode_exec){

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
            }else{
                printf("[%d]\n", pid);
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


//cd
int change_directory(Command_p cmd){
    if(cmd->nb_arg!=1){
        printf("argument incorrecte\n");
        return -1;
    }else{
        if(access(cmd->args[0], F_OK)==-1){
            printf("Aucun fichier ou dossier de ce nom\n");
            return -1;
        }
        if(access(cmd->args[0], X_OK)==-1){
            printf("permission non Permission non accordée\n");
        }

        if(chdir(cmd->args[0])!=0){
            printf("impossible d'acceder à ce dossier\n");
            return -1;
        }
    }
    return 0;
}

//pwd
char *print_working_directory(){
   char *dir = malloc(sizeof(char *)*PATH_MAX);
   if(dir==NULL){
    perror("pwd malloc");
    return NULL;
   }

    if(getcwd(dir, PATH_MAX)==NULL){
        printf("verifier votre PATH");
        free(dir);
        return NULL;
    }

    return dir;

}


