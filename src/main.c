#include<stdio.h>
#include<stdlib.h>
#include "../include/shell.h"
#include "../include/command.h"





int main(){

	char buff[LEN_STDIN];
	Command_elm * cmd = _init_command();
	Command_elm * cmd_shell = _init_command();



	fgets(buff, LEN_STDIN, stdin);
	buff[strcspn(buff, "\n")] = '\0';
	
	cmd_shell = add_cmd(cmd, buff);
	execute_command(cmd_shell, FIL);
	exit_cmd(cmd_shell, FIL);


	

	/*while(1){

		printf("~");
		if(fgets(buff, LEN_STDIN, stdin)!=NULL){

			buff[LEN_STDIN - 1] = '\0';

			if(strcmp("\n", buff)==0){
				exit(EXIT_FAILURE);
			}




		}else{
			printf("continue to play petty evil");
			break;
		}
	}*/

	return 0;
}
