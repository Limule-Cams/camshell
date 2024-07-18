#include<stdio.h>
#include<stdlib.h>
#include "../include/shell.h"
#include "../include/command.h"




int main(){

	char buff[LEN_STDIN];
	char file[] = ".C_history";
	Command_elm * cmd = _init_command();
	Command_elm * cmd_shell = _init_command();

	while(1){

		print_content_history_file(file);
		printf("~");
		if(fgets(buff, LEN_STDIN, stdin)!=NULL){

			buff[LEN_STDIN - 1] = '\0';

			if(strlen(buff)==0){
				exit(EXIT_FAILURE);
			}

			cmd_shell = add_cmd(cmd, buff);


		}else{
			printf("continue to play petty evil");
			break;
		}
	}

	return 0;
}
