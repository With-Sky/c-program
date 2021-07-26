#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

int n,count,max1;
long max2;
float t1,t2;
bool prime[1996416576];
int main()
{
    printf("enter a number bigger than 3\n");
    scanf("%ld",&n);
    t1=clock();
    for(register long i=0;i<n;i++)
        prime[i]=1;
    for(register long i=4;i<n;i+=2)
        prime[i]=0;
    max1 = sqrt(n);
    for(register int a=3;a<=max1;a+=2)
        if(prime[a])
        {
            max2 = n/a;
            for(register int b=a;b<=max2;b+=2)
                prime[a*b] = 0;
        }
    t2=clock();
    for(register int out=2;out<=n;out++)
    {
        if(prime[out])
        {
            count++;
            //printf("%ld\n",out);
        }
    }
    printf("time-consuming:%fs,gennerate:%d",(t2-t1)/1000,count);
    return 0;
}