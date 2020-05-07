# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>

int n = 10;
int count = 0;
char world[10][10];
int X_PlayerPosition=0, Y_PlayerPosition=0;

//ฟังค์ชั่น
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

//สุ่มขยะ
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
///////////////////////////////////////////////////////////////////ตั้งบอร์ด//////////////////////////////////////////
char c;
do{
    printf("ยินดีต้อนรับผู้เล่น 8=เดินขึ้น,2=เดินลง,4=เดินซ้าย,6=เดินขวา\n");
    printf("T,R,C-ขยะ, X-แพ้, W-นำขยะไปใช้ใหม่, P-ผู้เล่น ,S-คะแนน\n");
    printf("มีขยะ %d ชิ้น\n",count);
    printf("เก็บขยะให้มากที่สุดแล้วนำไปรีไซเคิล!!!!\n\n");
for(i=0; i<n; i++)
{
    for(j=0; j<n; j++)
    {
        printf("%c ", world[i][j] );
    }
    printf("\n");
}
printf("กดปุ่ม Enter เพื่อเดิน: ");
scanf("%d", &playersMove);
TRUE = movePlayer(playersMove, world, X_PlayerPosition, Y_PlayerPosition);
system("cls");
}while(TRUE != -1 &&TRUE != 2);
system("pause");
}
///////////////////////////////////////////////////////////ฟังค์ชั่น//////////////////////////////////////////////////////////////
int movePlayer(int playersMove, char world[][n], int X_Position, int Y_Position)
/////ตำแหน่งตัวละคร////////
{
    int tempi = X_Position;
    int tempj = Y_Position;
    int TRUE;
    if(playersMove == 8)
    {
        X_PlayerPosition -= 1;
    }
    else if(playersMove ==2 )
    {
        X_PlayerPosition += 1;
    }
    else if(playersMove == 6)
    {
        Y_PlayerPosition += 1;
    }
    else if(playersMove == 4)
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
     if(world[X_Position][Y_Position] == 'X')
    {
        printf("You Lose, Thank You for Playing\n");
        return -1;
    }
    if(world[X_Position][Y_Position] == 'W')
    {
        printf("Congratulations you win !\n");
        system("pause");
        return 2;
    }
return 1;
}

int wallCheck(int playersMove, char world[][10], int X_Position, int Y_Position)
{
    if(X_Position<0 && Y_Position<0 && (playersMove== 8 || playersMove==4))
    {
        printf("Can't move there\n");
        return 0;
    }
    else if(X_Position<0 && Y_Position>9 && (playersMove== 8 || playersMove==6))
    {
        printf("Can't move there\n");
        return 0;
    }
    else if(X_Position>9 && Y_Position<0 && (playersMove== 2 || playersMove==4))
    {
        printf("Can't move there\n");
        return 0;
    }
    else if(X_Position>9 && Y_Position<0 && (playersMove== 2 || playersMove==6))
    {
        printf("Can't move there\n");
        return 0;
    }
    else
    {
        if(X_Position < 0 && playersMove == 8)
        {printf("Can't move there\n");
            return 0;}
        if(X_Position > 9 && playersMove == 2)
        {printf("Can't move there\n");
            return 0;}
        if(Y_Position < 0 && playersMove == 4)
        {printf("Can't move there\n");
            return 0;}
        if(Y_Position > 9 && playersMove == 6)
        {printf("Can't move there\n");
            return 0;}
    }
return 1;
}

int moveCheck_2(int playersMove, char world[][10], int X_Position, int Y_Position)
{
    if(world[X_Position][Y_Position] == 'X')
    {
        printf("คุณแพ้แล้ว, ขอบคุณที่มาเล่นเกมของเรา\n");
        return 0;
    }
return 1;
}
