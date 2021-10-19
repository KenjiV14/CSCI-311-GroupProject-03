#include "rpsGame.h"

// Name of move
char* getIdMove(int id) {
    switch(id){
        case 0: return "Rock";
        case 1: return "Paper";
        case 2: return "Scissors";
        default: return "Unknown";
    }
}

int main(int argc, char *argv[]) {
    // Variables for Server
    int err, cSocket;
    struct sockaddr_in mainServAddress;
    struct sockaddr_in gameServAddress;
    char Buf[BUFL];
    char fromClient[BUFL];
    int cSocLen;

    // Variables for Game
    char playerMove[BUFL];
    int roundState;
    int waitBuffer = 0;

    // Connection to Main Server
    memset(&mainServAddress, 0, sizeof(struct sockaddr_in));
    mainServAddress.sin_family = AF_INET;
    mainServAddress.sin_port = htons(SERVERPORT);
    mainServAddress.sin_addr.s_addr = inet_addr(SERVERIP);
    cSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (cSocket == -1) {
        perror("socClient: socket creation failed");
        exit(1);
    }

    err =
        connect(cSocket, (struct sockaddr *)&mainServAddress, sizeof(struct sockaddr_in));
    if (err == -1) {
        perror("socClient: connect failed");
        exit(2);
    }
    // Server connection made. Game can be played.

    // Receive instructions from Server
    err = recv(cSocket, Buf, BUFL, 0);
    if (err == -1) {
        perror("socClient: read failed");
        exit(5);
    }

    // Connection to Game Server
    memset(&mainServAddress, 0, sizeof(struct sockaddr_in));
    gameServAddress.sin_family = AF_INET;
    gameServAddress.sin_port = htons(atoi(Buf));
    gameServAddress.sin_addr.s_addr = inet_addr(SERVERIP);

    close(cSocket);

    cSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (cSocket == -1) {
        perror("socClient: socket creation failed");
        exit(1);
    }

    err =
        connect(cSocket, (struct sockaddr *)&gameServAddress, sizeof(struct sockaddr_in));
    if (err == -1) {
        perror("socClient: connect failed\n");
        exit(2);
    }

    err = recv(cSocket, Buf, BUFL, 0);
    if(err == -1){
        perror("socClient: recv Failed.\n")
    }

    // RockPaperScissorGame Code
    while(1){

        printf("Choose Move: [R]ock, [P]aper, [S]cissor --> ");
        scanf("%s", Buf);

        cpyString(playerMove, Buf);
        sndString(cSocket, Buf);

    }

    /*
        err = send(cSocket, "Connection made!\n", 17, 0);
        printf("socClient: number of bytes sent to server: %d\n", err);
        err = recv(cSocket, Buf, BUFL, 0);
        if (err == -1) {
            perror("socClient: read failed");
            exit(5);
        }
        printf("socClient: msg from server: %s\n", Buf);
    */

    exit(0);
}