#include<stdio.h>
#include<stdlib.h>
#include "../include/shell.h"
#include "../include/command.h"




int main(){

	char buff[LEN_STDIN];
	Command_elm * cmd = _init_command();
	Command_elm * cmd_shell = _init_command();

	while(1){

		printf("~");
		if(fgets(buff, LEN_STDIN, stdin)!=NULL){

			buff[LEN_STDIN - 1] = '\0';

			cmd_shell = add_cmd(cmd, buff);
			if(cmd_shell->cmd == NULL){
				perror("erreur dans la fonction add_cmd");
			}


			if(strcmp(cmd_shell->cmd, "exit")==0){  
				memfree(cmd_shell);
				fprintf(stdout, "vous quittez le programme");
				break;
			}

			if(strcmp(cmd_shell->cmd, "history")==0) print_current_history(cmd_shell);
			cmd = cmd_shell;

		}else{
			fprintf(stdin, "Erreur de lecture de la commande");
			break;
		}
	}

	return 0;
}
