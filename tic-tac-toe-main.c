#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<stdlib.h>

char position[10]={'0','1','2','3','4','5','6','7','8','9'};//global veriable to identify position of input

int check_winer();//function to cheak game progress and find winner or draw
void game_board();//function to show game structure and visual in consol
void win_score(int x);//function to show and store score


int main(){
        int player=1,i,choice;
        char mark;//X,O

    do{
        game_board();
        player=(player%2)?1:2;
        printf("\n\tplayer %d,enter choice:",player);
        scanf("%d",&choice);
        mark=(player==1)?'X':'O';
    if(choice==1&&position[1]=='1')
        position[1]=mark;
    else if(choice==2&&position[2]=='2')
        position[2]=mark;
    else if(choice==3&&position[3]=='3')
        position[3]=mark;
    else if(choice==4&&position[4]=='4')
        position[4]=mark;
    else if(choice==5&&position[5]=='5')
        position[5]=mark;
    else if(choice==6&&position[6]=='6')
        position[6]=mark;
    else if(choice==7&&position[7]=='7')
        position[7]=mark;
    else if(choice==8&&position[8]=='8')
        position[8]=mark;
    else if(choice==9&&position[9]=='9')
        position[9]=mark;
    else{
        printf("\tInvalid option!\nEnter a valid position(0 to 9):");
        player--;
        getch();
    }
    i=check_winer();
    player++;


    }while(i==-1);
    game_board();

    if(i==1){
        printf("\n\n\t==>Player%d won!<==",--player);
        win_score(player);

    }
    else{
        printf("\n\n\t==<Game draw!>==");

    }
         printf("\n\t==>Press Enter to Quit<==");

        getch();
        return 0;

}

int check_winer(){
    if(position[1]==position[2]&&position[2]==position[3])
        return 1;
    else if(position[4]==position[5]&&position[5]==position[6])
        return 1;
    else if(position[7]==position[8]&&position[8]==position[9])
        return 1;
    else if(position[1]==position[4]&&position[4]==position[7])
        return 1;
    else if(position[2]==position[5]&&position[5]==position[8])
        return 1;
    else if(position[3]==position[6]&&position[6]==position[9])
        return 1;
    else if(position[1]==position[5]&&position[5]==position[9])
        return 1;
    else if(position[3]==position[5]&&position[5]==position[7])
        return 1;
    else if(position[1]!= '1'&& position[2]!= '2'&& position[3]!= '3'&& position[4]!= '4'&& position[5]!= '5'&& position[6]!= '6'&& position[7]!= '7'&& position[8]!= '8'&& position[9]!= '9')
        return 0;
    else
        return -1;

}

void game_board(){
    //system("color 0A");
   system("cls");

    printf("\n\n\n\t\t Tic Tac Toe\n\n\n");

	printf("\tPlayer1 (X) - Player2 (O) \n\n\n");
	printf("\t\t     |     |     \n");
	printf("\t\t  %c  |  %c  |  %c  \n",position[1],position[2],position[3]);
	printf("\t\t_____|_____|_____\n");
	printf("\t\t     |     |     \n");
	printf("\t\t  %c  |  %c  |  %c  \n",position[4],position[5],position[6]);
	printf("\t\t_____|_____|_____\n");
	printf("\t\t     |     |     \n");
	printf("\t\t  %c  |  %c  |  %c  \n",position[7],position[8],position[9]);
	printf("\t\t     |     |     \n");

}

void win_score(int x){
        int y,z;

    FILE *fp1,*fp2;
    if(x==1){
    fp1=fopen("player1-score-file.txt","r");
    fscanf(fp1,"%d",&y);
    y=y+1;
    fclose(fp1);
      fp1=fopen("player1-score-file.txt","w");
      fprintf(fp1,"%d",y);
      printf("\n\t!!Player1 won %d times!!\n",y);
   fclose(fp1);}

   else if(x==2){
    fp2=fopen("player2-score-file.txt","r");
    fscanf(fp2,"%d",&z);
    z=z+1;
    fclose(fp2);
      fp2=fopen("player2-score-file.txt","w");
      fprintf(fp2,"%d",z);
      printf("\n\t!!Player2 won %d times!!\n",z);
   fclose(fp2);}

}

