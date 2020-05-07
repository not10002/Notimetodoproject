# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>


int n = 10;
int count = 0;
char world[10][10];
int iPlayerPosition=0, jPlayerPosition=0;

//Functions 
int movePlayer(int playersMove, char world[][10], int iPosition, int jPosition);
int moveCheck(int playersMove, char world[][10], int iPosition, int jPosition);
int wallCheck(int playersMove, char world[][10], int iPosition, int jPosition);
int moveCheck2(int playersMove, char world[][10], int iPosition, int jPosition);



int main(void)
{
    int seed = time(NULL);
    srand(seed);
    
    int playersMove;
    int i,j,k;
    int iRandom=rand()%n + 0 , jRandom =rand()%n + 0;
    int TRUE;
    
    
    /****เริ่มตั้ง *********///
   for(i=0; i<n; i++)
     for(j=0; j<n; j++)
       {
                  world[i][j] = '0'; 
       }//*/
    
    
    world[0][0] = 'P';
    world[n-1][n-1] = 'W';
    
   
    for(k=0; k < n*(.3); k++)
    {
             if(world[iRandom][jRandom] == '0')
             {
                                         world[iRandom][jRandom] = 'T';
                                         
                                         iRandom = rand()%n + 0;
                                         jRandom = rand()%n + 0;
             }                     
              //*/  
    }
    for(k=0; k < n*(.5); k++)
    {
             if(world[iRandom][jRandom] == '0')
             {
                                         world[iRandom][jRandom] = 'R';
                                         
                                         iRandom = rand()%n + 0;
                                         jRandom = rand()%n + 0;
             }                     
              //*/  
    }
    for(k=0; k < n*(.7); k++)
    {
             if(world[iRandom][jRandom] == '0')
             {
                                         world[iRandom][jRandom] = 'C';
                                         
                                         iRandom = rand()%n + 0;
                                         jRandom = rand()%n + 0;
             }                     
              //*/  
    }
    
   for(k=0; k < n*(0.5); k++)
    {
             if(world[iRandom][jRandom] == '0')
             {
                                          world[iRandom][jRandom] = 'X';
                                         iRandom = rand()%n + 0;
                                         jRandom = rand()%n + 0;
                                        
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
   
     
      TRUE = movePlayer(playersMove, world, iPlayerPosition, jPlayerPosition);
     
     
     system("cls");
     }while(TRUE != -1 &&TRUE != 2);
    
     
     
    system("pause");
}

///////////////////////////////////////////////////////////FUNCTIONS//////////////////////////////////////////////////////////////
int movePlayer(int playersMove, char world[][n], int iPosition, int jPosition)
{
    int tempi = iPosition;
    int tempj = jPosition;
    int TRUE;
    
   
    if(playersMove == 8)
    {
                   iPlayerPosition -= 1;
    }
    else if(playersMove ==2 )
    {
                   iPlayerPosition += 1;
    }
    else if(playersMove == 6)
    {
                   jPlayerPosition += 1;
    }
    else if(playersMove == 4)
    {
                   jPlayerPosition -= 1;
    }
    
    TRUE = moveCheck(playersMove, world, iPlayerPosition, jPlayerPosition);
    if( TRUE == 1 && wallCheck(playersMove, world, iPlayerPosition, jPlayerPosition) == 1)
    {
    
    char temp = world[tempi][tempj];
    world[tempi][tempj] =world[iPlayerPosition][jPlayerPosition];
    world[iPlayerPosition][jPlayerPosition] = temp;
   
    return TRUE;
    }
    else
    {
        iPlayerPosition = iPosition;
        jPlayerPosition = jPosition;
        
        return TRUE;
    }
    
}

int moveCheck(int playersMove, char world[][10], int iPosition, int jPosition)
{
    if(world[iPosition][jPosition] == 'T')
    {
      world[iPosition][jPosition] = '.';
                                 count +=1;
                            
    }
    if(world[iPosition][jPosition] == 'R')
    {
      world[iPosition][jPosition] = '.';
                                 count +=1;
                            
    }
    if(world[iPosition][jPosition] == 'C')
    {
      world[iPosition][jPosition] = '.';
                                 count +=1;
                            
    }
     if(world[iPosition][jPosition] == 'X')
    {
         printf("You Lose, Thank You for Playing\n");
         
         return -1;
    }
    if(world[iPosition][jPosition] == 'W')
    {
                                 printf("Congratulations you win !\n");
                                 system("pause");
                                 return 2;
    }
    
    return 1;
}

int wallCheck(int playersMove, char world[][10], int iPosition, int jPosition)
{
    
    if(iPosition<0 && jPosition<0 && (playersMove== 8 || playersMove==4))
    {
                    printf("Can't move there\n");
                    return 0;
    }
    else if(iPosition<0 && jPosition>9 && (playersMove== 8 || playersMove==6))
    {
                    printf("Can't move there\n");
                    return 0;
    }
    else if(iPosition>9 && jPosition<0 && (playersMove== 2 || playersMove==4))
    {
                    printf("Can't move there\n");
                    return 0;
    }
    else if(iPosition>9 && jPosition<0 && (playersMove== 2 || playersMove==6))
    {
                    printf("Can't move there\n");
                    return 0;
    }
    else
    {
           if(iPosition < 0 && playersMove == 8)
           {printf("Can't move there\n");
                    return 0;}
           if(iPosition > 9 && playersMove == 2)
           {printf("Can't move there\n");
                    return 0;}
           if(jPosition < 0 && playersMove == 4)
           {printf("Can't move there\n");
                    return 0;}
           if(jPosition > 9 && playersMove == 6)
           {printf("Can't move there\n");
                    return 0;}
    }
    
    return 1;
}

int moveCheck2(int playersMove, char world[][10], int iPosition, int jPosition)
{
     if(world[iPosition][jPosition] == 'X')
    {
         printf("You Lose, Thank You for Playing\n");
         return 0;
    }
    
    return 1;
}