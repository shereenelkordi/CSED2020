#include <string.h>
#include "main1.h"
#include "functions.h"
#include "files.h"

///save the game board to file save2
void save_gameboard(){
int i,j;
char  game_file[32][32];
for(i=0;i<numRow+1;i++){
  for(j=0;j<numCol+1;j++){
    if(gameboard[i][j]==' '){
      game_file[i][j]=0+48;
    }
    else {
       game_file[i][j]=gameboard[i][j];
    }
  }
}
FILE*save2;
save2=fopen("save2.txt","w");
fprintf(save2,"%d %d\n",numRow,numCol);
for(i=0; i<numRow+1; i++)
    {
        for(j=0; j<numCol+1; j++)
        {
    fprintf(save2,"%c ",game_file[i][j]);
        }
    fprintf(save2,"\n");
    }

fclose(save2);
}
///save details to file save3

void save_detail(){
  FILE*save3;
save3=fopen("save3.txt","w");
fprintf(save3,"%d\n",num_move);
fprintf(save3,"%d\n",num_flag);
fprintf(save3,"%d\n",num_question);
fprintf(save3,"%d\n",time_move);
fclose(save3);
}
///in case of loading a saved game
void load_gameboard()
{
    int i,j;
  char game_file[32][32];
    FILE*save2;
    save2=fopen("save2.txt","r");
    if(save2==NULL){
     return ;
    }
    fscanf(save2,"%d %d\n",&numRow,&numCol);
    while(!feof(save2))
    {
        for(i=0; i<numRow+1; i++)
        {
            for(j=0; j<numCol+1; j++)
            {
                if((i==0)&&(j==0))
                {
                    fscanf(save2,"   \n%c ",&game_file[i][j]);
                }
                else
                {
                    fscanf(save2,"%c ",&game_file[i][j]);
                }
            }
          fscanf(save2,"\n");
        }
    }

    fclose(save2);
   for(i=0;i<numRow+1;i++){
  for(j=0;j<numCol+1;j++){
    if(game_file[i][j]==0+48){
      gameboard[i][j]=' ';
    }
   else {
    gameboard[i][j]=game_file[i][j];
   }
  }
}


}

void load_detail(){
FILE*save3;
save3=fopen("save3.txt","r");
if(save3==NULL){
    printf("the file does not Exist\n");
    main_menu();
    }
else{
if(isEmpty(save3)==0){
   printf("there is no saved game \n");
 main_menu();
}
else {
if(!feof(save3)){
   fscanf(save3,"%d\n",&num_move);
   fscanf(save3,"%d\n",&num_flag);
   fscanf(save3,"%d\n",&num_question);
   fscanf(save3,"%d\n",&time_move);
}
fclose(save3);
}
}
}
