// var env manage

#include"../include/vars.h"

void print_var(char *var) {
    char *val=getenv(var);
    if(val!=NULL)
        printf("La variable %s a la valeur : %s\n",var,val);
    else
        printf("La variable %s n’a pas été assignée\n",var);
}

void show_env_vars() {
    char **env = environ;
    while (*env) {
        printf("%s\n", *env);
        env++;
    }
}