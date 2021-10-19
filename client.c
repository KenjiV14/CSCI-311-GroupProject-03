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
    int err, cSocket;
    struct sockaddr_in mainServAddress;
    struct sockaddr_in gameServAddress;
    char Buf[BUFL];
    char fromClient[BUFL];
    int cSocLen;

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
        perror("socClient: connect failed");
        exit(2);
    }

    

    printf("%s\n", Buf);
    err = send(cSocket, " ", 1, 0);

    while (1) {
        // Receive game status from Server
        err = recv(cSocket, Buf, BUFL, 0);
        if (err == -1) {
            perror("socClient: read failed");
            exit(5);
        }
        printf("%s", Buf);
        err = send(cSocket, " ", 1, 0);
        
        // Receive input options from Server
        err = recv(cSocket, Buf, BUFL, 0);
        if (err == -1) {
            perror("socClient: read failed");
            exit(5);
        }
        printf("%s", Buf);
        // err = send(cSocket, " ", 1, 0);

        // Get input from user
        scanf("%s", fromClient);

        // Send input to server
        err = send(cSocket, fromClient, strlen(fromClient) + 1, 0);

        // Server sends info about win/lose/tie
        err = recv(cSocket, Buf, BUFL, 0);
        if (err == -1) {
            perror("socClient: read failed");
            exit(5);
        }
        printf("%s\n", Buf);
        err = send(cSocket, " ", 1, 0);
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
    close(cSocket);
    exit(0);
}