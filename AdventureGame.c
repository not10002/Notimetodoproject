# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>


int n = 10;
int count = 0;
char world[10][10];
int XPlayerPosition=0, YPlayerPosition=0;

//Functions 
int movePlayer(int playersMove, char world[][10], int XPosition, int YPosition);
int moveCheck(int playersMove, char world[][10], int XPosition, int YPosition);
int wallCheck(int playersMove, char world[][10], int XPosition, int YPosition);
int moveCheck2(int playersMove, char world[][10], int XPosition, int YPosition);



int main(void)
{
    int seed = time(NULL);
    srand(seed);
    int playersMove;
    int i,j,k;
    int XRandom=rand()%n + 0 , YRandom =rand()%n + 0;
    int TRUE;

    /****เริ่มตั้ง *********///
   for(i=0; i<n; i++)
     for(j=0; j<n; j++)
       {
            world[i][j] = '0'; 
       }


    world[0][0] = 'P';
    world[n-1][n-1] = 'W';

    for(k=0; k < n*(.3); k++)
    {
             if(world[XRandom][YRandom] == '0')
            {
                world[XRandom][YRandom] = 'T';
                XRandom = rand()%n + 0;
                YRandom = rand()%n + 0;
            }
    }
    for(k=0; k < n*(.5); k++)
    {
            if(world[XRandom][YRandom] == '0')
            {
                world[XRandom][YRandom] = 'R';
                XRandom = rand()%n + 0;
                YRandom = rand()%n + 0;
            }
    }
    for(k=0; k < n*(.7); k++)
    {
        if(world[XRandom][YRandom] == '0')
             {
                                         world[XRandom][YRandom] = 'C';
                                         
                                         XRandom = rand()%n + 0;
                                         YRandom = rand()%n + 0;
             }                     
              //*/  
    }
    
   for(k=0; k < n*(0.5); k++)
    {
             if(world[XRandom][YRandom] == '0')
             {
                                          world[XRandom][YRandom] = 'X';
                                         XRandom = rand()%n + 0;
                                         YRandom = rand()%n + 0;
                                        
             }  
    }
    
    
  
     for(i=0; i<n; i++)
         for(j=0; j<n; j++)
       {
                   if(world[i][j] == '0')
                  world[i][j] = '.'; 
       }//*/  
   
    
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
      
     printf("Enter your move: ");
     scanf("%d", &playersMove);
   
     
      TRUE = movePlayer(playersMove, world, XPlayerPosition, YPlayerPosition);
     
     
     system("cls");
     }while(TRUE != -1 &&TRUE != 2);
    
     
     
    system("pause");
}

///////////////////////////////////////////////////////////FUNCTIONS//////////////////////////////////////////////////////////////
int movePlayer(int playersMove, char world[][n], int XPosition, int YPosition)
/////ตำแหน่งตัวละคร////////
{
    int tempi = XPosition;
    int tempj = YPosition;
    int TRUE;

    if(playersMove == 8)
    {
       XPlayerPosition -= 1;////
    }
    else if(playersMove ==2 )
    {
                   XPlayerPosition += 1;
    }
    else if(playersMove == 6)
    {
                   YPlayerPosition += 1;
    }
    else if(playersMove == 4)
    {
                   YPlayerPosition -= 1;
    }
    
    TRUE = moveCheck(playersMove, world, XPlayerPosition, YPlayerPosition);
    if( TRUE == 1 && wallCheck(playersMove, world, XPlayerPosition, YPlayerPosition) == 1)
    {
    
    char temp = world[tempi][tempj];
    world[tempi][tempj] =world[XPlayerPosition][YPlayerPosition];
    world[XPlayerPosition][YPlayerPosition] = temp;
   
    return TRUE;
    }
    else
    {
        XPlayerPosition = XPosition;
        YPlayerPosition = YPosition;
        
        return TRUE;
    }
    
}

int moveCheck(int playersMove, char world[][10], int XPosition, int YPosition)
{
    if(world[XPosition][YPosition] == 'T')
    {
      world[XPosition][YPosition] = '.';
                                 count +=3;
                            
    }
    if(world[XPosition][YPosition] == 'R')
    {
      world[XPosition][YPosition] = '.';
                                 count +=2;
                            
    }
    if(world[XPosition][YPosition] == 'C')
    {
      world[XPosition][YPosition] = '.';
                                 count +=1;
                            
    }
     if(world[XPosition][YPosition] == 'X')
    {
         printf("You Lose, Thank You for Playing\n");
         
         return -1;
    }
    if(world[XPosition][YPosition] == 'W')
    {
                                 printf("Congratulations you win !\n");
                                 system("pause");
                                 return 2;
    }
    
    return 1;
}

int wallCheck(int playersMove, char world[][10], int XPosition, int YPosition)
{
    
    if(XPosition<0 && YPosition<0 && (playersMove== 8 || playersMove==4))
    {
                    printf("Can't move there\n");
                    return 0;
    }
    else if(XPosition<0 && YPosition>9 && (playersMove== 8 || playersMove==6))
    {
                    printf("Can't move there\n");
                    return 0;
    }
    else if(XPosition>9 && YPosition<0 && (playersMove== 2 || playersMove==4))
    {
                    printf("Can't move there\n");
                    return 0;
    }
    else if(XPosition>9 && YPosition<0 && (playersMove== 2 || playersMove==6))
    {
                    printf("Can't move there\n");
                    return 0;
    }
    else
    {
           if(XPosition < 0 && playersMove == 8)
           {printf("Can't move there\n");
                    return 0;}
           if(XPosition > 9 && playersMove == 2)
           {printf("Can't move there\n");
                    return 0;}
           if(YPosition < 0 && playersMove == 4)
           {printf("Can't move there\n");
                    return 0;}
           if(YPosition > 9 && playersMove == 6)
           {printf("Can't move there\n");
                    return 0;}
    }
    
    return 1;
}

int moveCheck2(int playersMove, char world[][10], int XPosition, int YPosition)
{
     if(world[XPosition][YPosition] == 'X')
    {
         printf("You Lose, Thank You for Playing\n");
         return 0;
    }
    
    return 1;
}
