/****************************************************************
* Team Members: Steven Severin, Kenji Vang, Florentine Niyongere
* CSCI - 311
* Star-Id: bn5377xd, ka7354jz
* Date: 10/20/2021
* rpsGame.h
****************************************************************/

#ifndef RPSGAME_H
#define RPSGAME_H

#include <netdb.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <time.h>

#define BUFL 100
#define SERVERPORT 45756
#define SERVERPORTSTR "45756"
#define SERVERIP "199.17.28.80"
#define SERVERNAME ""

void sndInt(int socket, int data);

void sndString(int socket, char* data);

int genRandGame();

int getServerPlay();

char *getIdMove(int id);

int determineWinner(int s, int c);

#endif
