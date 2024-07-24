#ifndef _SESSION_H_
#define _SESSION_H_

#include"parser.h"

void print_content_history_file(char *file);
void print_current_history(Command_p cmd);
void add_file(Command_p cmd, char *file);

#endif