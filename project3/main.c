#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <conio.h>
#include "functions.h"
#include "savings.h"
#include "winOrlose.h"

int numRow=31;
int numCol=31;
int myboard[31][31];
char gameboard[31][31];
int num_move=0;
int num_flag=0;
int num_question=0;
int time_move=0;



int main()
{
    welcome();
  main_menu();

    return 0;
}


     /**initialize the game board**/
     void game_board(int firstRow,int firstCol){
         int i=0,j=0;
         for(j=0;j<=numCol;j++){
            gameboard[0][j]=j+48;
         }
         for(i=0;i<=numRow;i++){
            gameboard[i][0]=i+48;
         }
         for(i=1;i<=numRow;i++){
            for(j=1;j<=numCol;j++){
                gameboard[i][j]='X';
            }
         }
         if(myboard[firstRow][firstCol]>0 ){
            gameboard[firstRow][firstCol]=myboard[firstRow][firstCol]+48;
             }
    else {if(myboard[firstRow][firstCol]==0){open(firstRow,firstCol);}}
         print_gameborad();
     }

     void play(){
     clock_t start,End;
     start=clock();
     printf("Press F to put flag,? to put a question mark, O to open a cell:\n");
     char c; c=getch();
     printf("%c\n",c);
     int x=0,y=0;
     switch(c){
       case 'F':
         num_move++;
        num_flag++;
        printf("Enter Row Number: ");
        x=intCheckXs();
        printf("Enter Column Number: ");
        y=intCheckYs();
        gameboard[x][y]='F';
       End=clock();
      time_move+=(double)(End-start)/CLOCKS_PER_SEC;
        print_gameborad();
        break;

       case '?':
          num_move++;
        num_question++;
        printf("Enter Row Number: ");
        x=intCheckXs();
        printf("Enter Column Number: ");
        y=intCheckYs();
        gameboard[x][y]='?';
        End=clock();
       time_move+=(double)(End-start)/CLOCKS_PER_SEC;
        print_gameborad();
        break;

      case 'O':
         num_move++;
        printf("Enter Row Number: ");
        x=intCheckXs();
        printf("Enter Column Number: ");
        y=intCheckYs();
        if(myboard[x][y]>0 && (gameboard[x][y]=='X' || gameboard[x][y]=='?') ){
            gameboard[x][y]=myboard[x][y]+48;
            End=clock();
            time_move+=(double)(End-start)/CLOCKS_PER_SEC;
             print_gameborad();}
        else if (myboard[x][y]+48==gameboard[x][y]){
        openedCell(x,y);
        End=clock();
      time_move+=(double)(End-start)/CLOCKS_PER_SEC;
        print_gameborad();
        }
        else if(myboard[x][y]==-1 && gameboard[x][y]!='F'){
            End=clock();
            time_move+=(double)(End-start)/CLOCKS_PER_SEC;
            losing(x,y);}/**cell contains a mine**/
        else {if(myboard[x][y]==0 && gameboard[x][y]!='F'){open(x,y);
        End=clock();
       time_move+=(double)(End-start)/CLOCKS_PER_SEC;
        print_gameborad();}}/**empty cell**/
        break;
     default: printf("Enter a valid operation\n");
     }
     win();
     play();
     }

     void print_detail()
{
    int  time_minutes=time_move/60;
    int  time_seconds=time_move%60;
    printf("moves=%d\n",num_move);
    printf("flags=%d\n",num_flag);
    printf("question marks=%d\n",num_question);
    printf("Time passed: %.2d:%.2d\n",time_minutes,time_seconds);
}
     void print_gameborad(){
         int i=0,j=0;
         system("cls");
         /**printing number of columns**/
         for(j=0;j<numCol+1;j++){
            if(j==0){printf("  \t");}
            else{printf("%C \t",j+48);}
            }printf("\n\n");
            /**printing the game board and the number of rows**/
         for(i=1;i<numRow+1;i++){
            for(j=0;j<numCol+1;j++){
                if(j==0){printf("%C \t",i+48);}
                else{printf("%c \t",gameboard[i][j]);}
                }
                printf("\n\n");}
        print_detail();
          saveGame();
     }
     /**if an empty cell is opened, all empty cells around it should be opened
     until it reaches a number or the borders of the board**/
     void open(int x ,int y){
   if(x<1 || x>numRow || y<1 || y>numCol){/**stop when a border is reached**/
   return ;
   }
   else{ /**checking if the cell is closed and empty otherwise it's already visited**/
    if(gameboard[x][y]=='X' && myboard[x][y]==0){
     gameboard[x][y]=' ';
    open(x-1,y);
    open(x,y-1);
    open(x+1,y);
    open(x,y+1);
    open(x+1,y+1);
    open(x-1,y-1);
    open(x-1,y+1);
    open(x+1,y-1);
   }
   if(gameboard[x][y]=='X'  && myboard[x][y]>0){ /**once you reach a number open the cell and stop the recursion**/
    gameboard[x][y]=myboard[x][y]+48;
    return;
   }
   }
} /// in case of opening an opened cell all 8 nearby cells should be opened except the ones marked with flags
    ///only if the number in the cell is equal to the number of flags around it
    void openedCell(int x, int y){
        int i,j,count; i=j=count=0;
        for(i=x-1;i<=x+1;i++){
            for(j=y-1;j<=y+1;j++){
                if(gameboard[i][j]=='F'){count=count+1;}
            }
        }
        if(myboard[x][y]==count){
            for(i=x-1;i<=x+1;i++){
            for(j=y-1;j<=y+1;j++){
                    if(gameboard[i][j]!='F'){
                        if( myboard[i][j]>0 ){
                            gameboard[i][j]=myboard[i][j]+48;
                        }
                        else if(myboard[i][j]==0){open(i,j);}
                        else {if(myboard[i][j]==-1){losing(i,j);}}
                    }
                }
            }
        }
    }

int player_detail()
{
    int score=((pow(numRow,4))*(pow(numCol,4)))/(num_move*time_move);
    return score;
}
