#include "rpsGame.h"

int main(int argc, char *argv[]) {
    int err, sSocket, cSocket;
    struct sockaddr_in sAddr;
    struct sockaddr_in cAddr;
    char Buf[BUFL];
    int cSocLen;

    memset(&sAddr, 0, sizeof(struct sockaddr_in));
    sAddr.sin_family = AF_INET;
    sAddr.sin_port = htons(newPort);
    sAddr.sin_addr.s_addr = inet_addr(SERVERIP);
    sSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (sSocket == -1){
        perror("socServerG: socket creation failed.\n");
        exit(1);
    }

    // Binds Address to socket
    err = bind(sSocket, (struct sockaddr*)&sAddr, sizeof(struct sockaddr_in));
    if(err = -1){
        perror("socServerG: Bind address Failed.\n");
        exit(2);
    }

    err = listen(sSocket, 5);
    if(err == -1){
        perror("socServerG: Listen Failed.\n");
        exit(3);
    }
}