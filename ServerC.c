#include "rpsGame.h"

int main(int argc, char *argv[]) {
    int err, id, sSocket, cSocket;
    struct sockaddr_in sAddr;
    struct sockaddr_in cAddr;
    char Buf[BUFL];
    int cSocLen;

    sSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (sSocket == -1) {
        perror("socServerC: socket creation failed\n");
        exit(1);
    }

    memset(&sAddr, 0, sizeof(struct sockaddr_in));
    sAddr.sin_family = AF_INET;
    sAddr.sin_port = htons(SERVERPORT);
    sAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    err = bind(sSocket, (struct sockaddr *)&sAddr, sizeof(struct sockaddr_in));
    if (err == -1) {
        perror("socServerC: bind address to socket failed\n");
        exit(2);
    }

    err = listen(sSocket, 5);
    if (err == -1) {
        perror("socServerC: listen failed\n");
        exit(3);
    }

    printf("Server is awaiting connections\n");
    // Port bound for listening. We can fork from here

while(1){
    cSocket = accept(sSocket, (struct sockaddr *)&cAddr, &cSocLen);
    if (cSocket == -1) {
        perror("socServerC: accept failed\n");
        exit(4);
    }
    printf("Accept Succesful.\n");

    id = fork();
    if(id == 0){    //Fork Child

    int offPort = SERVERPORT;

    char cSockString[(int)((ceil(log10(cSocket))+1)*sizeof(char))];
    char offPortString[(int)((ceil(log10(offPort))+1)*sizeof(char))];

    sprintf(cSockString, "%d", cSocket);
    sprintf(offPortString, "%d", offPort);

    printf("Child Created: Port - %d\n", offPort);
    err = execl("./ServerG", "ServerG", cSockString, offPortString, (char*)NULL);
    if(err = -1){
        perror("soServerC: exec Failed.\n");
        exit(5);
    }

    }else if(id < 0){
        perror("socServerC: Fork Failed.\n");
        exit(6);
    }
}


    /* Test starts here */
    // SDend instructions to client
/*    err = send(cSocket,
               "This is a game of Rock, Paper, Scissors.\nWe will play the "
               "best 2 of 3\n",
               71, 0);
    err = recv(cSocket, Buf, BUFL, 0);
    // Send game status to client
    err = send(cSocket, "This is game 1 of 3. The game is tied.\n", 40, 0);
    err = recv(cSocket, Buf, BUFL, 0);
    // Send input options to client
    err = send(cSocket, "Select [R]ock, [P]aper, [S]cissors: ", 37, 0);
    // Get input from client
    err = recv(cSocket, Buf, BUFL, 0);
    if (err == -1) {
        perror("socServer: read failed");
        exit(5);
    }
    printf("socServer: msg from client: %s\n", Buf);
    // Send back to client
    err = send(cSocket, "You Lost!\n", 11, 0);
    err = recv(cSocket, Buf, BUFL, 0);
    close(cSocket);
*/

    /* Test ends here */
    exit(0);
}
