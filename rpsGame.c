#include "rpsGame.h"

void sndInt(int socket, int data){
    int err;
    char dataString[(int)((ceil(log10(data))+1)*sizeof(char))];

    sprintf(dataString, "%d", data);
    err = send(socket, dataString, (sizeof dataString / sizeof(char)), 0);
    if(err == -1){
        perror("send Failed\n");
        exit(1);
    }
}

void sndString(int socket, char* data){
    int err;

    err = send(socket, data, strlen(data)+1, 0);
    if(err == -1){
        perror("send Failed.\n");
        exit(2);
    }
}