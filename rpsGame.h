/*********************************************************
* Team Members: Steven Severin, Kenji Vang
* CSCI - 311
* Star-Id: , ka7354jz, 
* Date: 10/20/2021
* rpsGame.h
*********************************************************/

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
#include <math.h>

#define BUFL 100
#define SERVERPORT 31200
#define SERVERPORTSTR "45756"
#define SERVERIP "199.17.28.80"
#define SERVERNAME ""

void sndInt(int socket, int data);

void sndString(int socket, char* data);

#endif