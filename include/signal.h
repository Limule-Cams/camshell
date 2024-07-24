#ifndef _SIGNAL_H_
#define _SIGNAL_H_


#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>


typedef struct {
    pid_t pid;
    char *name;
    char *status;
}sig_t;


void sig_quit();


#endif