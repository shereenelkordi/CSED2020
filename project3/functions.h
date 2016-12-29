#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>

#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED


void welcome();
int intCheckSize();
int intCheckXs();
int intCheckYs();
int is_valid_int_size(char *str);
int is_valid_int_X(char *str);
int is_valid_int_Y(char *str);
void main_menu();
void startGame();
void my_board(int firstRow, int firstCol);
void game_borad(int firstRow, int firstCol);
void play();
void mine(int arr1[][2],int size1, int firstRow, int firstCol );
void print_gameboard();
void open(int x, int y);
void openedCell(int x, int y);
void print_detail();
int player_detail();

typedef struct
{
    char*name[30];
    int score;
} player;
extern int numRow;
extern int numCol;
extern int myboard[31][31];
extern char gameboard[31][31];
extern int num_move;
extern int num_flag;
extern int num_question;
extern int time_move;

#endif // FUNCTIONS_H_INCLUDED
