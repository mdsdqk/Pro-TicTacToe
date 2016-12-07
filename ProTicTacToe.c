#include<stdio.h>
#include<stdlib.h>
#include"HighScore.c"

int grid[9]={0,0,0,0,0,0,0,0,0}, gridbig[9][9], pturn, turn=1, flag=1, gridnum, plchoice, comchoice, i, j,k, nextmove;
char box[9], boxbig[9][9];

char empty[9]={1,1,1,1,1,1,1,1,1};
int playorder[9]={4,0,2,6,8,1,3,5,7};
char pl1[9];
char pl2[9];
int e=-1,p1=0,p2=-1;


int gameplay();
int winP();
int pro();
int gameover();
int isgridfull();
void displayP();
void instructions();
int winPbig();
int eog();
int isbigfull();
void display();
char win();
int wp();
int wpp();
void play();



void main()

{ 
    int level,type;
    char name[30],cl="Y";
printf("Enter your Name    ");
scanf("%s",name);


//while(cl!='N');
//{


printf("SELECT TYPE\n1: Normal\n2: Pro");
scanf("%d",&type);
if(type==2)
{
    pro();
    insert(name,p1);
    HS();
    /*
    printf("Do you want to continue?");
    scanf("%c",&cl);

    if(cl!='N')
    */
    return ;

    //else
        //goto here;
}





printf("SELECT LEVEL\n1-Beginner\n2-Intermediate\n3-Advanced\n4-Legendary");
scanf("%d",&level);



    do{
      play(level);
    display();
    }
    while(!win());

    if(win()=='n')
        printf("Its A Tie!!");
    else
    printf("%c Wins!!!!",win());

printf("Do you want to continue?");
scanf("%c",&cl);


}

int pro()
{
    for(j=0; j<9; j++)
    {
        for(i=0; i<9; i++)
        {
            gridbig[j][i]=0;
        }
    }
    gameplay();
    printf("\n\n");

    return 0;
}

int gameplay()
{
    if(turn && flag)
    {
        instructions();
    }

    else if(!eog(gridbig))
    {
        while(isgridfull(gridbig[nextmove]) || winP(gridbig[nextmove]))
            {
                        nextmove++;

                        if(nextmove>=8)
                            nextmove=0;

            }
                        
            

        if(turn)
        {
            printf("\nPLAY IN BOX %d\n\n",nextmove+1);
            printf("Player 1 turn!\nEnter Box Number: ");

            while(1) 
            {
                scanf("%d", &pturn);
                if(gridbig[nextmove][pturn-1]!=0 || pturn<1 || pturn>9)
                    {
                        printf("Invalid!, The position is either filled or out of bounds\n");
                        printf("Please enter a valid position: ");
                    }
                else 
                    break;
            }
            gridbig[nextmove][pturn-1] = plchoice;
            turn = 0;
            p1++;
            nextmove=pturn-1;
            gameplay();
        }

     /*       
    if(wpP(gridbig[nextmove])==10)
    { 
      //if(wpp(gridbig[nextmove][])==10)
       // {
       int j=0;
       for(j=0;j<9;j++)
        if(gridbig[nextmove][playorder[j]]==NULL)
            break;
            
        gridbig[nextmove][8]='comchoice';

       // }

        //else 
            //gridbig[nextmove][wpp(gridbig[nextmove][])]='O';
    }
    else
    gridbig[nextmove][wpP(gridbig[nextmove])]='O';
    

      displayP();

    gameplay();



    //}
    */

        else
        {
            //printf("Player 2 turn!\nEnter Box Number: ");
            pturn = wpP(gridbig[nextmove])+1;
            if(pturn>9)
            {pturn=wppP(gridbig[nextmove])+1;

            if(pturn>9)
            {
                
                int i=0;
                pturn=playorder[i]+1;
                printf("%d",wpP(gridbig[pturn-1]));

                while (wpP(gridbig[playorder[i]])<10)
                {
                    i++;
                }
            
            //printf("%d",gridbig[nextmove][4]);
                while(gridbig[nextmove][playorder[i]]!=NULL)
                    i++;
                pturn=playorder[i]+1;

            }
            }
            
            /*while(1) 
            {
                //scanf("%d", &pturn);
                
                if(gridbig[nextmove][pturn-1]!=0 || pturn<1 || pturn>9)
                    {
                        printf("Invalid!, The position is either filled or out of bounds\n");
                        printf("Please enter a valid position: ");
                        
                    }
                else 
                    break;
            }*/
            gridbig[nextmove][pturn-1] = comchoice;
            turn = 1;
            nextmove=pturn-1;
            displayP();
            gameplay();
        }
        
    }

    else
    {
        if(winPbig(gridbig) == -1)
            printf("Congratulations! Player 1 wins.");

    
        else if(winPbig(gridbig) == 1)
        {
            printf("Congratulations, Player 2 wins");
            p1=100-p1;
        }
    
        else    
            printf("Well played, Its a Tie!");
    }
}

int winP(int board[9])
{
    unsigned winPs[8][3] = {{0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6}};
    for(i = 0; i < 8; ++i) 
    {
        if(board[winPs[i][0]] != 0 &&
           board[winPs[i][0]] == board[winPs[i][1]] &&
           board[winPs[i][0]] == board[winPs[i][2]])
                return board[winPs[i][2]];

           

           
    }
    return 0;
}

int winPbig(int board[9][9])
{
    unsigned winPs[8][3] = {{0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6}};
    for(j = 0; j < 8; j++) 
    {
        if(winP(board[winPs[j][0]]) != 0 &&
           winP(board[winPs[j][0]]) == winP(board[winPs[j][1]]) &&
           winP(board[winPs[j][0]]) == winP(board[winPs[j][2]]))
            return winP(board[winPs[j][2]]);
    }
    return 0;
}

int eog()
{
    if(winPbig(gridbig) || isbigfull(gridbig))
        return 1;
    
    return 0;
}

int isbigfull(int board[9][9])
{
    for(j=0;j<9;j++)
    {
        for(i=0; i<9; i++)
        {
            if(board[j][i]==0)
            {
                return 0;
            }
        }
    }
    return 1;
}

void instructions()
{
    printf("\nHey, Welcome to Pro Tic Tic Toe!\n");
    printf("The board is numbered as following\n");
    for(j=0; j<9; j+=3)
    {
        if(i<1)
        {
            printf("------------+-+-----------+-+------------\n");
            printf("|     %i     | |     %i     | |     %i     |\n", j+1, j+2, j+3);
            for(i=0; i<9; i+=3)
            {
                if(i==0)
                {
                    printf("------------+-+-----------+-+------------\n");
                    printf("| %d | %d | %d | | %d | %d | %d | | %d | %d | %d |\n", i+1, i+2, i+3, i+1, i+2, i+3, i+1, i+2, i+3);
                    printf("---+---+----+-+---+---+---+-+---+---+----\n");
                }
                else if(i==6)
                {
                    printf("| %d | %d | %d | | %d | %d | %d | | %d | %d | %d |\n", i+1, i+2, i+3, i+1, i+2, i+3, i+1, i+2, i+3);
                    printf("---+---+----+-+---+---+---+-+---+---+----\n");
                }
                else
                {
                    printf("| %d | %d | %d | | %d | %d | %d | | %d | %d | %d |\n", i+1, i+2, i+3, i+1, i+2, i+3, i+1, i+2, i+3);
                    printf("------------+-+-----------+-+------------\n");
                }
            }
        }
        else
        {
            printf("|     %i     | |     %i     | |     %i     |\n", j+1, j+2, j+3);
        for(i=0; i<9; i+=3)
        {
            if(i==0)
            {
                printf("------------+-+-----------+-+------------\n");
                printf("| %d | %d | %d | | %d | %d | %d | | %d | %d | %d |\n", i+1, i+2, i+3, i+1, i+2, i+3, i+1, i+2, i+3);
                printf("---+---+----+-+---+---+---+-+---+---+----\n");
            }
            else if(i==6)
            {
                printf("| %d | %d | %d | | %d | %d | %d | | %d | %d | %d |\n", i+1, i+2, i+3, i+1, i+2, i+3, i+1, i+2, i+3);
                printf("---+---+----+-+---+---+---+-+---+---+----\n");
            }
            else
            {
                printf("| %d | %d | %d | | %d | %d | %d | | %d | %d | %d |\n", i+1, i+2, i+3, i+1, i+2, i+3, i+1, i+2, i+3);
                printf("------------+-+-----------+-+------------\n");
            }
        }
        }
    }

    printf("Player 1: 'X' ; Player 2: 'O'\n");
        plchoice = -1;  //use -1 for X and 1 for O
        comchoice = 1;

    printf("for the first move, Player 1 can choose a grid to play\n");
    printf("enter grid number: ");
    while(1) 
            {
                scanf("%d", &gridnum);
                if(gridnum<1 || gridnum>9)
                    {
                        printf("Invalid!, The position is out of bounds\n");
                        printf("Please enter a valid position: ");
                    }
                else 
                    break;
            }
    printf("enter box number: ");
    while(1) 
            {
                scanf("%d", &pturn);
                if(pturn<1 || pturn>9)
                    {
                        printf("Invalid!, The position is out of bounds\n");
                        printf("Please enter a valid position: ");
                    }
                else 
                    break;
            }
    gridbig[gridnum-1][pturn-1] = plchoice;
    nextmove = pturn-1;
    displayP();
    turn=0;
    flag=0;
    gameplay();
}


void displayP()
{
    for(j=0; j<9; j++)
    {
        for(i=0; i<9; i++)
        {
            if(gridbig[j][i]==1)
                boxbig[j][i]='O';
            else if(gridbig[j][i]==-1)
                boxbig[j][i]='X';
            else
                boxbig[j][i]=' ';
        }
    }
    printf("\n");
    for(j=0; j<9; j+=3)
    {
        for(i=0; i<9; i+=3)
        {
            if(i==0)
            {
                printf("------------+-+-----------+-+------------\n");
                printf("| %c | %c | %c | | %c | %c | %c | | %c | %c | %c |\n", boxbig[j][i], boxbig[j][i+1], boxbig[j][i+2], boxbig[j+1][i], boxbig[j+1][i+1], boxbig[j+1][i+2], boxbig[j+2][i], boxbig[j+2][i+1], boxbig[j+2][i+2]);
                printf("---+---+----+-+---+---+---+-+---+---+----\n");
            }
            else if(i==6)
            {
                printf("| %c | %c | %c | | %c | %c | %c | | %c | %c | %c |\n", boxbig[j][i], boxbig[j][i+1], boxbig[j][i+2], boxbig[j+1][i], boxbig[j+1][i+1], boxbig[j+1][i+2], boxbig[j+2][i], boxbig[j+2][i+1], boxbig[j+2][i+2]);
                printf("---+---+----+-+---+---+---+-+---+---+----\n");
            }
            else
            {
                printf("| %c | %c | %c | | %c | %c | %c | | %c | %c | %c |\n", boxbig[j][i], boxbig[j][i+1], boxbig[j][i+2], boxbig[j+1][i], boxbig[j+1][i+1], boxbig[j+1][i+2], boxbig[j+2][i], boxbig[j+2][i+1], boxbig[j+2][i+2]);
                printf("------------+-+-----------+-+------------\n");
            }
        }
    }
    printf("\n");
}

int isgridfull(int board[9])
{
    for(i=0; i<9; i++)
    {
        if(board[i]==0)
        {
            return 0;
        }
    }
    return 1;
}




void display()
{
    printf("\n\n");
    printf(" %c|%c|%c",grid[0],grid[1],grid[2]);
    printf("\n-------\n");
    printf(" %c|%c|%c",grid[3],grid[4],grid[5]);
    printf("\n-------\n");
    printf(" %c|%c|%c",grid[6],grid[7],grid[8]);
    printf("\n-------\n");
    printf("\n\n");

}

int wpP(int grid[])
{

if(grid[1]!=NULL)
        {
            if(grid[0]==grid[1])
                if(grid[2]==NULL)
                    return 2;
            if(grid[2]==grid[1])
            if(grid[0]==NULL)
                    return 0;
            if(grid[7]==grid[1])
            if(grid[4]==NULL)
                    return 4;
        
          
        }

        if(grid[3]!=NULL)
        {
            if(grid[0]==grid[3])
            if(grid[6]==NULL)
                    return 6;
            if(grid[6]==grid[3])
            if(grid[0]==NULL)
                    return 0;
            if(grid[5]==grid[3])
            if(grid[4]==NULL)
                    return 4;
            
        }

        if(grid[7]!=NULL)
        {
            if(grid[8]==grid[7])
            if(grid[6]==NULL)
                    return 6;
            if(grid[6]==grid[7])
            if(grid[8]==NULL)
                    return 8;
        }

        if(grid[5]!=NULL)
        {
            if(grid[8]==grid[5])
            if(grid[2]==NULL)
                    return 2 ;
            if(grid[2]==grid[5])
            if(grid[8]==NULL)
                    return 8;
        }

        if(grid[4]!=NULL)
        {
            if(grid[0]==grid[4])
            if(grid[8]==NULL)
                    return 8;
            if(grid[8]==grid[4])
            if(grid[0]==NULL)
                    return 0;
            if(grid[2]==grid[4])
            if(grid[6]==NULL)
                    return 6;
            if(grid[6]==grid[4])
            if(grid[2]==NULL)
                    return 2;
            if(grid[1]==grid[4])
            if(grid[7]==NULL)
                    return 7;
            if(grid[7]==grid[4])
            if(grid[1]==NULL)
                    return 1;
            if(grid[3]==grid[4])
            if(grid[5]==NULL)
                    return 5;
            if(grid[5]==grid[4])
            if(grid[3]==NULL)
                    return 3;
            
            
        }

        if(grid[0]!=NULL)
        {
            if(grid[6]==grid[0])
            if(grid[3]==NULL)
                    return 3 ;
            if(grid[2]==grid[0])
            if(grid[1]==NULL)
                    return 1;
            if(grid[8]==grid[0])
            if(grid[4]==NULL)
                    return 4;
        }

         if(grid[8]!=NULL)
        {
            if(grid[2]==grid[8])
            if(grid[5]==NULL)
                    return 5 ;
            if(grid[6]==grid[8])
            if(grid[7]==NULL)
                    return 7;
            
        }




  


        return 10;


}




int wp(int level)
{
if(grid[1]=='O')
        {
            if(grid[0]=='O')
                if(empty[2])
                    return 2;
            if(grid[2]=='O')
                if(empty[0])
                    return 0;
            if(grid[7]=='O')
                if(empty[4])
                    return 4;
        
          
        }

        if(grid[3]=='O')
        {
            if(grid[0]=='O')
                if(empty[6])
                    return 6;
            if(grid[6]=='O')
                if(empty[0])
                    return 0;
            if(grid[5]=='O')
                if(empty[4])
                    return 4;
            
        }

        if(grid[7]=='O')
        {
            if(grid[8]=='O')
                if(empty[6])
                    return 6;
            if(grid[6]=='O')
                if(empty[8])
                    return 8;
        }

        if(grid[5]=='O')
        {
            if(grid[8]=='O')
                if(empty[2])
                    return 2 ;
            if(grid[2]=='O')
                if(empty[8])
                    return 8;
        }

        if(grid[4]=='O')
        {
            if(grid[0]=='O')
                if(empty[8])
                    return 8;
            if(grid[8]=='O')
                if(empty[0])
                    return 0;
            if(grid[2]=='O')
                if(empty[6])
                    return 6;
            if(grid[6]=='O')
                if(empty[2])
                    return 2;
            if(grid[1]=='O')
                if(empty[7])
                    return 7;
            if(grid[7]=='O')
                if(empty[1])
                    return 1;
            if(grid[3]=='O')
                if(empty[5])
                    return 5;
            if(grid[5]=='O')
                if(empty[3])
                    return 3;
            
            
        }

        if(grid[0]=='O')
        {
            if(grid[6]=='O')
                if(empty[3])
                    return 3 ;
            if(grid[2]=='O')
                if(empty[1])
                    return 1;
            if(grid[8]=='O')
                if(empty[4])
                    return 4;
        }

         if(grid[8]=='O')
        {
            if(grid[2]=='O')
                if(empty[5])
                    return 5 ;
            if(grid[6]=='O')
                if(empty[7])
                    return 7;
            
        }


if(level>1)
{
  if(grid[1]=='X')
        {
            if(grid[0]=='X')
                if(empty[2])
                    return 2;
            if(grid[2]=='X')
                if(empty[0])
                    return 0;
            if(grid[7]=='X')
                if(empty[4])
                    return 3;
        
          
        }

        if(grid[3]=='X')
        {
            if(grid[0]=='X')
                if(empty[6])
                    return 6;
            if(grid[6]=='X')
                if(empty[0])
                    return 0;
            if(grid[5]=='X')
                if(empty[4])
                    return 4;
            
        }

        if(grid[7]=='X')
        {
            if(grid[8]=='X')
                if(empty[6])
                    return 6;
            if(grid[6]=='X')
                if(empty[8])
                    return 8;
        }

        if(grid[5]=='X')
        {
            if(grid[8]=='X')
                if(empty[2])
                    return 2 ;
            if(grid[2]=='X')
                if(empty[8])
                    return 8;
        }

        if(grid[4]=='X')
        {
            if(grid[0]=='X')
                if(empty[8])
                    return 6;
            if(grid[8]=='X')
                if(empty[0])
                    return 0;
            if(grid[2]=='X')
                if(empty[6])
                    return 6;
            if(grid[6]=='X')
                if(empty[2])
                    return 2;
            if(grid[1]=='X')
                if(empty[7])
                    return 7;
            if(grid[7]=='X')
                if(empty[1])
                    return 1;
            if(grid[3]=='X')
                if(empty[5])
                    return 5;
            if(grid[5]=='X')
                if(empty[3])
                    return 3;
            
            
        }

         if(grid[0]=='X')
        {
            if(grid[6]=='X')
                if(empty[3])
                    return 3 ;
            if(grid[2]=='X')
                if(empty[1])
                    return 1;
            if(grid[8]=='X')
                if(empty[4])
                    return 4;
        }

         if(grid[8]=='X')
        {
            if(grid[2]=='X')
                if(empty[5])
                    return 5 ;
            if(grid[6]=='X')
                if(empty[7])
                    return 7;
            
        }
}


        return 10;


}

int wpp(int level)
{
if(level>3)
{

if(grid[4]=='O')
{

    if(grid[3]=='X'&& grid[5]=='X')
        if(empty[0])
            return 0;
        if(empty[2])
            return 2;
        if(empty[8])
            return 8;
        if(empty[6])
            return 6;
    if(grid[1]=='X' && grid[7]=='X')
        if(empty[0])
            return 0;
        if(empty[6])
            return 6;
    if(grid[1]==NULL && grid[7]==NULL)
        return 1;
    if(grid[3]==NULL && grid[5]==NULL)
        return 3;

    
    if(grid[1]=='X'&& grid[3]=='X')
        if(empty[0])
            return 0;
    if(grid[3]=='X'&& grid[7]=='X')
        if(empty[6])
            return 6;
    if(grid[7]=='X'&& grid[5]=='X')
        if(empty[8])
            return 8;
    if(grid[5]=='X'&& grid[1]=='X')
        if(empty[2])
            return 2;
}
}
return 10;

}

int wppP(int grid[])
{


if(grid[4]==1)
{

    if(grid[3]==-1 && grid[5]==-1)
        if(grid[0]==NULL)
            return 0;
        if(grid[2]==NULL)
            return 2;
        if(grid[8]==NULL)
            return 8;
        if(grid[6]==NULL)
            return 6;
    if(grid[1]==-1 && grid[7]==-1)
        if(grid[0]==NULL)
            return 0;
        if(grid[6]==NULL)
            return 6;
    if(grid[1]==NULL && grid[7]==NULL)
        return 1;
    if(grid[3]==NULL && grid[5]==NULL)
        return 3;

    
    if(grid[1]==-1 && grid[3]==-1)
        if(grid[0]==NULL)
            return 0;
    if(grid[3]==-1&& grid[7]==-1)
        if(grid[6]==NULL)
            return 6;
    if(grid[7]==-1&& grid[5]==-1)
        if(grid[8]==NULL)
            return 8;
    if(grid[5]==-1&& grid[1]==-1)
        if(grid[2]==NULL)
            return 2;

}
return 10;

}



char win()
{
        if(grid[0]!=NULL)
            if((grid[3]==grid[6] && grid[3]==grid[0]) ||(grid[1]==grid[2] && grid[1]==grid[0]) || (grid[4]==grid[8] && grid[8]==grid[0] ))
            {//printf("test1");
                return grid[0];
            
            }
        if(grid[4]!=NULL)
         if((grid[3]==grid[4] && grid[4]==grid[5]) ||(grid[1]==grid[4] && grid[4]==grid[7]) || (grid[2]==grid[4] && grid[4]==grid[6]))
            {
              //printf("test2");  
                return grid[4];
                
            }
        if(grid[8]!=NULL)
         if((grid[2]==grid[5] && grid[2]==grid[8])|| (grid[6]==grid[7] && grid[6]==grid[8]))
            {
                return grid[8];
           // printf("test3");
            }

       int i=0,flag=1;
        for (i=0;i<9;i++)
            {
                if(grid[i]==NULL)
                flag=0;
            }

            if(flag==1)
                {
                return('n');
                }

    return 0;

}

void play(int level)
{
    int pos;
    printf("enter posittion");
    scanf("%d",&pos);

    if(grid[pos-1]!=NULL || pos>9 || pos<1)
        printf("enter valid position");

    else{

    grid[pos-1]='X';
    p1++;
    pl1[p1]=pos;

    int i; 
    for(i=0;i<9;i++)
        {
            if(grid[i]!=NULL)
                empty[i]=0;
        }   
    
    if(win())
        return;
    


    p2++;
    if(wp(level)==10)
    { 
      if(wpp(level)==10)
        {
       int j=0;
       for(j=0;j<9;j++)
        if(grid[playorder[j]]==NULL)
            break;
        grid[playorder[j]]='O';

        }

        else 
            grid[wpp(level)]='O';
    }
    else
    grid[wp(level)]='O';
    }

    
}





