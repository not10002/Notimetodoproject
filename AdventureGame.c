# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>

int n = 10;
int count = 0;
char world[10][10];
int X_PlayerPosition=0, Y_PlayerPosition=0;

//Function
int movePlayer(int playersMove, char world[][10], int X_Position, int Y_Position);
int moveCheck(int playersMove, char world[][10], int X_Position, int Y_Position);
int wallCheck(int playersMove, char world[][10], int X_Position, int Y_Position);
int moveCheck_2(int playersMove, char world[][10], int X_Position, int Y_Position);

int main(void)
{
int seed = time(NULL);
srand(seed);
int playersMove;
int i,j,k;
int X_Random=rand()%n + 0 , Y_Random =rand()%n + 0;
int TRUE;

//Random Trash
for(i=0; i<n; i++)
    for(j=0; j<n; j++)
    {
        world[i][j] = '0';
    }

world[0][0] = 'P';
world[n-1][n-1] = 'W';

for(k=0; k < n*(.3); k++)
{
    if(world[X_Random][Y_Random] == '0')
    {
        world[X_Random][Y_Random] = 'T';
        X_Random = rand()%n + 0;
        Y_Random = rand()%n + 0;
    }
}
for(k=0; k < n*(.5); k++)
{
    if(world[X_Random][Y_Random] == '0')
    {
        world[X_Random][Y_Random] = 'R';
        X_Random = rand()%n + 0;
        Y_Random = rand()%n + 0;
    }
}
for(k=0; k < n*(.7); k++)
{
    if(world[X_Random][Y_Random] == '0')
    {
        world[X_Random][Y_Random] = 'C';
        X_Random = rand()%n + 0;
        Y_Random = rand()%n + 0;
    }
}
for(k=0; k < n*(0.5); k++)
{
    if(world[X_Random][Y_Random] == '0')
    {
        world[X_Random][Y_Random] = 'X';
        X_Random = rand()%n + 0;
        Y_Random = rand()%n + 0;
    }
}
for(i=0; i<n; i++)
    for(j=0; j<n; j++)
    {
        if(world[i][j] == '0')
        world[i][j] = '.';
    }
///////////////////////////////////////////////////Set up Board//////////////////////////////////////////
char c;
do{
    printf("Welcome to the game 8=up,2=down,4=left,6=right\n");
    printf("T,R,C-Trash, X-Lose, W-Recycle, P-Player ,S-Score\n");
    printf("You have %d Score\n",count);
    printf("Pickup trash to recycle!!!!\n\n");
for(i=0; i<n; i++)
{
    for(j=0; j<n; j++)
    {
        printf("%c ", world[i][j] );
    }
    printf("\n");
}
printf("Press the button Enter to walk: ");
scanf("%d", &playersMove);
TRUE = movePlayer(playersMove, world, X_PlayerPosition, Y_PlayerPosition);
system("cls");
}while(TRUE != -1 &&TRUE != 2);
system("pause");
}
////////////////////////////////Function walk///////////////////////////////////
int movePlayer(int playersMove, char world[][n], int X_Position, int Y_Position)
{
    int tempi = X_Position;
    int tempj = Y_Position;
    int TRUE;
    if(playersMove == 8)//go up
    {
        X_PlayerPosition -= 1;
    }
    else if(playersMove ==2 )//go down
    {
        X_PlayerPosition += 1;
    }
    else if(playersMove == 6)//go right
    {
        Y_PlayerPosition += 1;
    }
    else if(playersMove == 4)//go left
    {
        Y_PlayerPosition -= 1;
    }

    TRUE = moveCheck(playersMove, world, X_PlayerPosition, Y_PlayerPosition);
    if( TRUE == 1 && wallCheck(playersMove, world, X_PlayerPosition, Y_PlayerPosition) == 1)
    {
        char temp = world[tempi][tempj];
        world[tempi][tempj] =world[X_PlayerPosition][Y_PlayerPosition];
        world[X_PlayerPosition][Y_PlayerPosition] = temp;
        return TRUE;
    }
    else
    {
        X_PlayerPosition = X_Position;
        Y_PlayerPosition = Y_Position;
        return TRUE;
    }
}

int moveCheck(int playersMove, char world[][10], int X_Position, int Y_Position)
///////////////////////////////Check Item///////////////////////////////
{
    if(world[X_Position][Y_Position] == 'T')
    {
        world[X_Position][Y_Position] = '.';
        count +=3;
    }
    if(world[X_Position][Y_Position] == 'R')
    {
        world[X_Position][Y_Position] = '.';
        count +=2;
    }
    if(world[X_Position][Y_Position] == 'C')
    {
        world[X_Position][Y_Position] = '.';
        count +=1;
    }
     if(world[X_Position][Y_Position] == 'X')//ชนกับสิ่งกีดขวาง
    {
        printf("You lose,Thank you to playing\n");
        return -1;
    }
    if(world[X_Position][Y_Position] == 'W')//ชนกับเส้นชัย
    {
        printf("Congratulations, You Won!\n");
        printf("You have %d Score\n", count);
        system("pause");
        return 2;
    }
return 1;
}

int wallCheck(int playersMove, char world[][10], int X_Position, int Y_Position)
///////////////////////////////check wall///////////////////////////////
{
    if(X_Position<0 && Y_Position<0 && (playersMove== 8 || playersMove==4))
    {
        printf("No Way!!!!!\n");
        return 0;
    }
    else if(X_Position<0 && Y_Position>9 && (playersMove== 8 || playersMove==6))
    {
        printf("No Way!!!!!\n");
        return 0;
    }
    else if(X_Position>9 && Y_Position<0 && (playersMove== 2 || playersMove==4))
    {
        printf("No Way!!!!!\n");
        return 0;
    }
    else if(X_Position>9 && Y_Position<0 && (playersMove== 2 || playersMove==6))
    {
        printf("No Way!!!!!\n");
        return 0;
    }
    else
    {
        if(X_Position < 0 && playersMove == 8)
        {
            printf("No Way!!!!!\n");
            return 0;
        }
        if(X_Position > 9 && playersMove == 2)
        {
            printf("No Way!!!!!\n");
            return 0;
        }
        if(Y_Position < 0 && playersMove == 4)
        {
            printf("No Way!!!!!\n");
            return 0;
        }
        if(Y_Position > 9 && playersMove == 6)
        {
            printf("No Way!!!!!\n");
            return 0;
        }
    }
    return 1;
}

int moveCheck_2(int playersMove, char world[][10], int X_Position, int Y_Position)
{
    if(world[X_Position][Y_Position] == 'X')
    {
        printf("You lose,Thank you to playing\n");
        return 0;
    }
return 1;
}