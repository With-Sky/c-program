#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include <time.h>

bool ary1[23][23];
int ary2[529][2];
int len,direct,dir,judge,count,x,y,point;
float t1,t2,t3;
void food()//随机生成食物位置
{
    x=rand()%20+1;
    y=rand()%20+1;
    for(int i=0;i<len;i++)
        if(ary2[i][0]==x&&ary2[i][1]==y)
            food();
}
void snake(int direct,int x,int y)//生成蛇身坐标序列，打印蛇
{
    int dx=0,dy=0;
    switch(direct)
    {
        case 50:dy=-1;
        break;
        case 52:dx=-1;
        break;
        case 54:dx=1;
        break;
        case 56:dy=1;
    }
    if(ary2[0][0]+dx==x&&ary2[0][1]+dy==y)
    {
        ary2[len][0]=ary2[len-1][0];
        ary2[len][1]=ary2[len-1][1];
        len++;
        judge=1;
    }
    for(int i=len-1;i>0;i--)
    {
        ary2[i][0]=ary2[i-1][0];
        ary2[i][1]=ary2[i-1][1];
        ary1[ary2[i][0]][ary2[i][1]]=1;
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
    ary1[ary2[0][0]][ary2[0][1]]=1;
    ary1[x][y]=1;
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
                    {
                        printf("0");
                        count++;
                    }
                }
                else
                    printf(" ");
            }
        }
        if(n!=0&&n!=22)
            printf("|");
        printf("\n");
    }
    ary1[ary2[len-1][0]][ary2[len-1][1]]=0;
}
int main()
{
    len=1;
    judge=1;
    point=-1;
    ary2[0][0]=11;
    ary2[0][1]=11;
    t1=t2=clock();
    direct=50;
    printf("\n\n\n\n\n\n\n\n          按5开始");
    while(1)
    {
        if(_getch()==53)
        {
            while(1)//主循环
            {
                t2=clock();
                if(_kbhit())//获取键盘按下的键
                {
                    dir=_getch();
                    if(dir==50||dir==52||dir==54||dir==56)
                    if(direct+dir!=106)
                    direct=dir;
                }
                if(judge==1)
                {
                    srand(time(NULL));
                    food();
                    judge=0;
                    point++;
                }
                if(t2-t1>=200000)
                {
                    t3=clock();
                    clrscr();
                    count=0;
                    snake(direct,x,y);
                    t1=clock();
                    printf("%.1ffps\n%d分\n",1000000/(t1-t3),point*100);
                    if(point==count)
                        break;
                }
            }
            clrscr();
            printf("\n\n\n\n\n\n          Game Over");
            break;
        }
    }
    return 0;
}
