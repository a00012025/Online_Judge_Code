#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int c[1001][1001];
int max(int x,int y)
    {
    if(x>=y) return x;
    else return y;
    }
main()
{
 char s1[1001],s2[1001];
 int i,j;
 while(gets(s1))
    {
    gets(s2);
    memset(c,0,sizeof(c));
    for(i=1;i<=strlen(s1);i++)
        {
        for(j=1;j<=strlen(s2);j++)
            {
            if(s1[i-1]==s2[j-1]) c[i][j]=c[i-1][j-1]+1;
            else c[i][j]=max(c[i][j-1],c[i-1][j]);
            
            }
        }
    printf("%d\n",c[strlen(s1)][strlen(s2)]);
    }
}
