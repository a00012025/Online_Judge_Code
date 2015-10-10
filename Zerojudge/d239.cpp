#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int p[10000000],num[10000000];
main()
{
 int i,j,n;
 for(i=1;i<=9999999;i++) p[i]=1;
 memset(num,0,sizeof(num));
 for(i=2;i<=9999999;)
    {
    num[i]+=1;
    for(j=2;i*j<=9999999;j++)
        {
        p[i*j]=0;
        num[i*j]+=1;
        }
    for(j=i+1;p[j]==0;j++);
    i=j;
    }
 for(i=10;i<=9999999;i++)
    {
    if((num[i]==4)&&(num[i+1]==4)&&(num[i+2]==4)&&(num[i+3]==4)) break;
    }
 printf("%d\n",i);
}
