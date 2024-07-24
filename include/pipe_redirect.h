#ifndef _PIPE_REDIRECT_H_
#define _PIPE_REDIRECT_H_

#include"parser.h"

void redirect_stdin(Command_p cmd ,char *file);
void redirect_stdout(Command_p cmd, char *file, Bool mode);
void redirect_pipe(Command_p cmd);

#endif