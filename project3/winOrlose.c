#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include "functions.h"
#include "main1.h"
#include "savings.h"
#include "files.h"


 /**checking win, if all cells that does not contain mines are opened**/
    void win(){
        int i,j,flag; i=j=flag=0;
        for(i=1;i<=numRow;i++){
            for(j=1;j<=numCol;j++){
                if(myboard[i][j]>0 ){
                    if(gameboard[i][j]!=myboard[i][j]+48){flag=1;}
                }
               else { if(myboard[i][j]==0 &&gameboard[i][j]!=' ' ){flag=1;}}
            }
        }
        if(flag==0){
                for(i=1;i<=numRow;i++){
                    for(j=1;j<=numCol;j++){
                        if(myboard[i][j]==-1){gameboard[i][j]='F';}
                    }
                }
                print_gameborad();
                remove_file();   ///remove the saved game
                system("COLOR 2");
                printf("YOU WIN\n");
                List_players();
                system("COLOR 7");
               printf("if you want to play again Enter (Y) or press any key to exit:\n");
                char c; c=getch();
                printf("%c",c);
               if(c=='Y'){
                num_move=0;num_flag=0;num_question=0;
                system("cls");
                main_menu();
               }
               else exit(0);
                }

    } ///open a cell that contains mine, the player loses
    void losing(int x,int y){
        int i,j; i=j=0;
        for(i=1;i<numRow+1;i++){
            for(j=1;j<numCol+1;j++){
                if(myboard[i][j]>0){
            gameboard[i][j]=myboard[i][j]+48;
            }
           else if(myboard[i][j]==0){gameboard[i][j]=' ';}
           else if(myboard[i][j]==-1 && gameboard[i][j]=='F'){gameboard[i][j]='*';}
           else if(myboard[i][j]==-1 && gameboard[i][j]!='F'){gameboard[i][j]='M';}
           if(myboard[i][j]!=-1 && gameboard[i][j]=='F'){gameboard[i][j]='-';}
            }
        }
        gameboard[x][y]='!';
        print_gameborad();
        system("COLOR 4");
        printf("you Lose\n");
       remove_file();
       system("pause");      ///remove the game that was saved in the file
       system("COLOR 7");
        printf("if you want to play again Enter (Y) or press any key to exit:\n");
         char c; c=getch(); printf("%c",c);
               if(c=='Y'){
                num_move=0;num_flag=0;num_question=0;
                system("cls");
                main_menu();
               }
               else exit(0);
    }
