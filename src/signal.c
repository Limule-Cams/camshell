#include "../include/signal.h"

/*
gestion des signaux sigint, sigchild, sigstop
qui serviront à implémenter les fonctionnalités telsque bg, fg
type sig_t pour la gestion des processus fils qui servira à implémenter jobs (affiche la liste des processus lancés par le shell)

réecriture de la fonction extern_cmd pour gérer le signal Ctrl+c et Ctrl+v
*/ 