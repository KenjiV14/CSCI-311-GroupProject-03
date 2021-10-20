#include "rpsGame.h"

void sndInt(int socket, int data) {
    int err;
    char dataString[BUFL];

    sprintf(dataString, "%d", data);
    err = send(socket, dataString, (sizeof dataString / sizeof(char)), 0);
    if (err == -1) {
        perror("send Failed\n");
        exit(1);
    }
}

void sndString(int socket, char *data) {
    int err;

    err = send(socket, data, strlen(data) + 1, 0);
    if (err == -1) {
        perror("send Failed.\n");
        exit(2);
    }
}

int genRandGame() {
    int i;
    time_t t;
    srand((unsigned)time(&t));

    while (1) {
        switch (i = rand() % 10) {
        case 3:
        case 5:
        case 7:
        case 9:
            return i;
        }
    }
}

int getServerPlay() {
    time_t t;
    srand((unsigned)time(&t));

    return rand() % 3;
}
char *getIdMove(int id) {
    switch (id) {
    case 0:
        return "Rock";
    case 1:
        return "Paper";
    case 2:
        return "Scissors";
    default:
        return "Unknown";
    }
}
int determineWinner(int s, int c) {
    if (s == c) {
        // Tie, redo game
        return 0;
    } else if ((s == 0 & c == 2) | (s == 1 & c == 0) | (s == 2 & c == 1)) {
        // Server wins
        return 1;
    } else if ((c == 0 & s == 2) | (c == 1 & s == 0) | (c == 2 & s == 1)) {
        // Client wins
        return 2;
    } else {
        // Something went wrong
        return -1;
    }
}
