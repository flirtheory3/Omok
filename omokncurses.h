#ifndef __OMOKNCURSES_H__
#define __OMOKNCURSES_H__

#include <ncurses.h>
#include <stdio.h>
#include <string.h>


int winidentifier(char* board[19][20]);
int omokManager(char user1[], char user2[], char* board[19][20], char user_id);
int chooseModeWindow();
#endif
