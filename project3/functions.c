#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "functions.h"
#include "savings.h"
#include "files.h"
#include "main1.h"

void welcome(){
    printf("                                WELCOME TO\n                                MINESWEEPER\n");
    system("pause");
    system("cls");
}/**checking if the user enters an integer number**/
///checking the size
int is_valid_int_size(char *str){
    int num, i, len = strlen(str);
    for (i = 0; i < len; i++)
        if (!isdigit(str[i]))
            return 0;
    num = atoi(str);
    if (num > 1 && num <= 30)
        return num;
    else
        return 0;
} /**scanning numbers**/
int intCheckSize(){
    char input[128]; int x;
    do
    {

        scanf("%s", input);
    } while (!is_valid_int_size(input));
    x=atoi(input);
    return x;}
int is_valid_int_X(char *str){
    int num, i, len = strlen(str);
    for (i = 0; i < len; i++)
        if (!isdigit(str[i]))
            return 0;
    num = atoi(str);
    if (num >=1 && num <= numRow)
        return num;
    else
        return 0;
} ///checking the num row entered while playing
///conditions are different for the coordinates as the board might be of size m*n
int intCheckXs(){
    char input[128]; int x;
    do
    {

        scanf("%s", input);
    } while (!is_valid_int_X(input));
    x=atoi(input);
    return x;}
int is_valid_int_Y(char *str){
    int num, i, len = strlen(str);
    for (i = 0; i < len; i++)
        if (!isdigit(str[i]))
            return 0;
    num = atoi(str);
    if (num >= 1 && num <= numCol)
        return num;
    else
        return 0;
} ///checking the num col entered while playing
int intCheckYs(){
    char input[128]; int x;
    do
    {

        scanf("%s", input);
    } while (!is_valid_int_Y(input));
    x=atoi(input);
    return x;}

void main_menu()
{
  printf("ENTER (N)to start a new game ENTER (L)to load game ENTER (R)to view ranks \n");
   char mark; mark=getch();
    printf("%c\n",mark);
  switch(mark){
  case 'N':startGame();
  break;
  case 'L':loadGame();
  break;
  case 'R':save_player();
  break;
  default:printf("Enter a valid character: \n");
   main_menu();
  }
} ///reading the size of the board and the first move from the user
void startGame(){
    printf("Enter Number Of Rows: ");
    numRow=intCheckSize();
    printf("Enter Number Of Columns: ");
    numCol=intCheckSize();
    clock_t start,End;
    start=clock();

    int firstRow,firstCol;
    printf("Enter your first Row: ");
    firstRow=intCheckXs();
    printf("Enter your first Col: ");
    firstCol=intCheckYs();

    End=clock();
   time_move=(double)(End-start)/CLOCKS_PER_SEC;
   num_move++;
    my_board(firstRow,firstCol);
    game_board(firstRow,firstCol);
    play();
}

    void my_board(int firstRow, int firstCol){
    int i=0,j=0,k=0;/**initializing my board**/
    for(i=0;i<=numRow;i++){
        for(j=0;j<=numCol;j++){
            myboard[i][j]=0;
        }
    }
    int numMine=1+(numRow*numCol)/10;
    int indexes[numMine][2];
    mine(indexes,numMine,firstRow,firstCol);
    /**placing mines inside the board,-1 represents a mine**/
    for(i=0;i<numMine;i++){
        myboard[indexes[i][0]][indexes[i][1]]=-1;
    }
    /**adding numbers around the mines starting from the left upper corner**/
    for(i=0;i<numMine;i++){
        for(j=-1;j<=1;j++){
            for(k=-1;k<=1;k++){
                if(myboard[indexes[i][0]+j][indexes[i][1]+k]!=-1 && indexes[i][0]+j >0 && indexes[i][0]+j <=numRow
                    && indexes[i][1]+k >0 && indexes[i][1]+k <= numCol ){/**checking if nearby cells contain mines
                        so not accessing the cell of the mine itself and checking for borders **/
                    myboard[indexes[i][0]+j][indexes[i][1]+k]++;
                }
            }
        }
    }


    }

    void mine(int arr1[][2], int size,int firstRow, int firstCol ){
        int n=50,arr2[size+n][2],i=0,j=0,k=0;
        srand(time(NULL));
        for(i=0;i<size+n;i++){ /**generating random indexes of the mines more than the required**/
            arr2[i][0]=1+rand()%numRow;
            arr2[i][1]=1+rand()%numCol;
        }
        for(i=0;i<size+n;i++){ /**removing repeated indexes**/
            for(j=i+1;j<size+n;j++){
                if(arr2[i][0]==arr2[j][0] && arr2[i][1]==arr2[j][1]){
                    for(k=j;k<size+n;k++){
                        arr2[k][0]=arr2[k+1][0]; arr2[k][1]=arr2[k+1][1];
                    } n--;j--;
                }
            }
        }
        for(i=0;i<size+n;i++){ /**if the first move of the player contains a mine, remove it**/
            if(arr2[i][0]==firstRow && arr2[i][1]==firstCol){
                for(j=i;j<size+n;j++){
                    arr2[j][0]=arr2[j+1][0]; arr2[j][1]=arr2[j+1][1];
                } n--;j--;
            }
        } /**the final array of indexes with almost the exact same number of mines**/
        for(i=0;i<size;i++){
            for(j=0;j<2;j++){
                arr1[i][j]=arr2[i][j];
            }
        }

    }
