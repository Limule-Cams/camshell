# Minishell unix
This shell is a work in progress


```
tree output :
.
├── build
│   └── amelioration
├── include
│   ├── fonction.h
│   ├── parser.h
│   ├── pipe_redirect.h
│   ├── session.h
│   ├── Shell.h
│   ├── signal.h
│   └── vars.h
├── main.c
├── makefile
├── README.md
├── src
│   ├── fonction.c
│   ├── parser.c
│   ├── pipe_redirect.c
│   ├── session.c
│   ├── Shell.c
│   ├── signal.c
│   └── vars.c
└── tests
    └── N00bshell

```

## compilation 

```
git clone https://github.com/Limule-Cams/camshell.git
cd camshell
mkdir build tests
make
./tests/N00shell 
```


## Description file

main.c

    Description: Main entry point of the program. This file handles command-line arguments passed to the shell and starts the shell.
    Role: Initialization of the shell and handling arguments.

src/shell.c

    Description: Contains the main code of the shell, including the read-execute loop for user commands.
    Role: Constructs the shell and manages the execution of user commands.

src/fonction.c

    Description: Contains the implementations of the built-in functions of the shell.
    Role: Provides internal shell functionalities like cd, exit, etc.
    Associated Header: include/fonction.h

src/parser.c

    Description: Handles the parsing of user-entered commands.
    Role: Analyzes commands and arguments for correct execution.
    Associated Header: include/parser.h

src/pipe_redirect.c

    Description: Manages piping (|) and file redirections (<, >, >>).
    Role: Allows communication between commands via pipes and redirects input/output.
    Associated Header: include/pipe_redirect.h

src/session.c

    Description: Manages shell sessions.
    Role: Maintains command history and handles session information.
    Associated Header: include/session.h

src/signal.c

    Description: Handles signals such as SIGINT, SIGSTOP, etc.
    Role: Ensures proper signal management for operations like stopping and resuming processes.
    Associated Header: include/signal.h

src/vars.c

    Description: Manages environment variables and possibly shell variables.
    Role: Provides mechanisms to manage and manipulate environment and shell variables.
    Associated Header: include/vars.h


Directories

build : Description: Directory used to store object files during compilation before linkage.

include : Description: Contains all header files for the various modules of the project.

src : Description: Contains all source files of the project.

tests : Description: Directory intended for shell tests.


README.md
Description: Main documentation file for the project, containing information on the project, how to set it up, and how to use it.