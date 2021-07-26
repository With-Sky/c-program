#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
bool ary1[23][23];
int ary2[529][2];
int len,direct,dir,d,judge,count,x,y;
float t1,t2,t3;

#include <windows.h>
static void SetPos(int x, int y)
{ 
       COORD point = { x, y };
       HANDLE HOutput = GetStdHandle(STD_OUTPUT_HANDLE);
       SetConsoleCursorPosition(HOutput, point);
}
void food()
{
    x=rand()%20+1;
    y=rand()%20+1;
    for(int i=0;i<len;i++)
        if(ary2[i][0]==x&&ary2[i][1]==y)
        {
            food();
            break;
        }
}
void snake(int direct,int x,int y)
{
    int dx=0,dy=0;
    switch(direct)
    {
        case 119:dy=-1;
        break;
        case 97:dx=-1;
        break;
        case 100:dx=1;
        break;
        case 115:dy=1;
    }
    for(int i=len-1;i>0;i--)
    {
        ary2[i][0]=ary2[i-1][0];
        ary2[i][1]=ary2[i-1][1];
    }
    ary2[0][0]+=dx;
    ary2[0][1]+=dy;
    if(ary2[0][0]==0)
        ary2[0][0]=21;
    else if(ary2[0][0]==22)
        ary2[0][0]=1;
    if(ary2[0][1]==0)
        ary2[0][1]=21;
    else if(ary2[0][1]==22)
        ary2[0][1]=1;
    if(ary2[0][0]==x&&ary2[0][1]==y)
    {
        ary2[len][0]=ary2[len-1][0];
        ary2[len][1]=ary2[len-1][1];
        len++;
        judge=1;
    }
    for(int m=0;m<=22;m++)
        for(int n=0;n<=22;n++)
            ary1[m][n]=0;
    ary1[x][y]=1;
    for(int i=0;i<len;i++)
    {
        ary1[ary2[i][0]][ary2[i][1]]=1;
    }
    for(int n=0;n<=22;n++)
    {
        if(n!=0&&n!=22)
            printf("|");
        for(int m=0;m<=22;m++)
        {
            if(n==0||n==22)
                printf("-");
            else
            {
                if(ary1[m][n])
                {
                    if(m==x&&n==y&&(ary2[0][0]!=x||ary2[0][1]!=y))
                        printf("@");
                    else
                        printf("0");
                }
                else
                    printf(" ");
            }
        }
        if(n!=0&&n!=22)
            printf("|");
        printf("\n");
    }
}
int main()
{
    len=1;
    count=2;
    judge=1;
    ary2[0][0]=7;
    ary2[0][1]=7;
    t1=t2=clock();
    direct=119;
    printf("\n\n\n\n\n\n\n\n          Press SPACE to start");
    while(1)
    {
        if(_getch()==32)
        {
            printf("start");
            while(1)
            {
                t2=clock();
                if(_kbhit())
                {
                    dir=_getch();
                    if(dir==119||dir==115||dir==97||dir==100)
                    if(direct+dir!=234&&direct+dir!=197)
                        direct=dir;
                }
                if(judge==1)
                {
                    srand(time(NULL));
                    food();
                    judge=0;
                }
                if(t2-t1>=200)
                {
                    t3=clock();
                    SetPos(0,0);
                    snake(direct,x,y);
                    t1=clock();
                    printf("%.1ffps\n%dpoint\n",1000/(t1-t3),(len-1)*100);
                }
            }
        }
    }
    return 0;
}