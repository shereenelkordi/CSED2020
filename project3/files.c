
#include <string.h>
#include "main1.h"
#include "functions.h"


///saving the game
void save_myboard(){
int i,j;
FILE*save1;
save1=fopen("save1.txt","w");
fprintf(save1,"%d %d\n",numRow,numCol);
for(i=0; i<numRow+1; i++)
    {
        for(j=0; j<numCol+1; j++)
        {
    fprintf(save1,"%d ",myboard[i][j]);
        }
    fprintf(save1,"\n");
    }

fclose(save1);
}
///saving names and scores in case of winning
void List_players()
{
    int i;
   char name[30],temp1[30];
    player List[50];
   int score=player_detail();
    int j,index=-1,temp,num_name;  ///index is the number of array list that has the same name as entered
    printf("Enter your name\n");
    scanf(" %[^\n]s", &name);
    for(i=0; name[i]!='\0'; i++)
    {
        if((name[i]>='A')&&(name[i]<='Z'))
        {
            char k=name[i];
            name[i]='a'+(k-'A');
        }
      num_name=i+2;
    }
    for(i=0;name[i]!='\0';i++){
    if(name[i]==' '){ ///changing spaces entered in the name to _ so that it could be read from the file after that
      name[i]='_';
    }
  }
    ///if the file is empty then register the first player
    FILE*users;
 users=fopen("users.txt","r");
 if (users == NULL)
    {
  users=fopen("users.txt","w");
   fprintf(users,"%s %d\n",name,score);
    return ;
    }

 for(i=0; i<50; i++)
    {
        List[i].score=0;
    }


        if(!feof(users))
    {
        for(i=0; i<50; i++)
        {
          fscanf(users,"%s %d\n",&List[i].name,&List[i].score);
        }
    }
   int k=0;
   while(List[k].score!=0){
    k++;
   }
 int index_list=k;/// number of players registered
    fclose(users);
    for(j=0; j<index_list; j++)
    {
    if(strcmp(name,List[j].name)==0){
           index=j;
         break;
    }
    }///if the player is found add the new score to the previous one
if(index!=-1){
 List[index].score=List[index].score+score;
 /**arrange scores and names**/
for(i=0;i<index_list;i++){
    for(j=i+1;j<index_list;j++){
       if(List[i].score<List[j].score){
        temp=List[i].score;
        List[i].score=List[j].score;
        List[j].score=temp;
       strcpy(temp1,List[i].name);
       strcpy(List[i].name,List[j].name);
       strcpy(List[j].name,temp1);
       }
    }
 }
users=fopen("users.txt","w");
 for(i=0;i<index_list;i++){
   fprintf(users,"%s %d\n",List[i].name,List[i].score);
 }
 fclose(users);
}
///if the player was not found add the name and the score
 else
 {
  List[index_list].score=score;
  strcpy(List[index_list].name,name);
/**arrange scores and names**/
for(i=0;i<index_list+1;i++){
    for(j=i+1;j<index_list+1;j++){
       if(List[i].score<List[j].score){
        temp=List[i].score;
        List[i].score=List[j].score;
        List[j].score=temp;
       strcpy(temp1,List[i].name);
       strcpy(List[i].name,List[j].name);
       strcpy(List[j].name,temp1);
       }
    }
 }
 users=fopen("users.txt","w");
 for(i=0;i<index_list+1;i++){
   fprintf(users,"%s %d\n",List[i].name,List[i].score);
 }
 fclose(users);
 }
}

void saveGame(){
save_myboard();
 save_gameboard();
save_detail();
}

///check if the file is empty and returns zero otherwise returns one
int  isEmpty(FILE *file)
{
    long savedOffset = ftell(file);
    fseek(file, 0, SEEK_END);

    if (ftell(file) == 0)
    {
        return 0;
    }

    fseek(file, savedOffset, SEEK_SET);
    return 1;
}
void load_myboard()
{
   int i,j;
    FILE*save1;
    save1=fopen("save1.txt","r");
   if(save1 == NULL){
     return ;
    }

    fscanf(save1,"%d %d\n",&numRow,&numCol);
    while(!feof(save1))
    {
        for(i=0; i<numRow+1; i++)
        {
            for(j=0; j<numCol+1; j++)
            {
                if((i==0)&&(j==0))
                {
                    fscanf(save1,"   \n%d ",&myboard[i][j]);
                }
                else
                {
                    fscanf(save1,"%d ",&myboard[i][j]);
                }
            }
          fscanf(save1,"\n");
        }
    }
    fclose(save1);

}

/**in case of winning or losing, remove what has been saved**/
void remove_file(){
remove_file1();
remove_file2();
remove_file3();
}
void remove_file1()
{
    FILE *save1;
  save1=fopen("save1.txt","w");
   int remove(const char *save1);
}
void remove_file2()
{
    FILE *save2;
  save2=fopen("save2.txt","w");
   int remove(const char *save2);
}
void remove_file3()
{
    FILE *save3;
  save3=fopen("save3.txt","w");
   int remove(const char *save3);
}


void loadGame(){
load_gameboard();
load_myboard();
load_detail();
  print_gameborad();
  play();
}
///printing ranks

void save_player(){
int i;
    player List[50];
    for(i=0; i<50; i++)
    {
        List[i].score=0;
    }
    ///if the file is empty
    FILE*users;
  users=fopen("users.txt","r");
    if (users == NULL)
    {
        printf("File does not exists \n");
        main_menu();
        return;
    }
    ///if the file was not empty, read it and print it to the screen
        if(!feof(users))
    {
        for(i=0; i<50; i++)
        {
          fscanf(users,"%s %d\n",List[i].name,&List[i].score);
        }
    }
   int k=0;
   while(List[k].score!=0){
    k++;
   }
    fclose(users);
char string1[50];
int index_list=k; int j=0;
for(i=0;i<index_list;i++){
  strcpy(string1,List[i].name);
   for(j=0;string1[j]!='\0';j++){
    if(string1[j]=='_'){ ///change back the _ to space while printing it on screen
     string1[j]=' ';
    }
  }
strcpy(List[i].name,string1);
}

for(i=0; i<index_list; i++)
        {
 printf("%s %d\n",List[i].name,List[i].score);
        }
   main_menu();
}
