#include<stdio.h>
#include<stdlib.h>
#include "../include/shell.h"




int main(){

	char cmd[LEN_STDIN], *token;

	while(1){

		if(fgets(cmd, LEN_STDIN, stdin)!=NULL){

			printf("~");

			cmd[LEN_STDIN - 1] = '\0';
		   


		}else{
			fprintf(stdin, "Erreur de lecture de la commande");
			break;
		}
	}

	return 0;
}
