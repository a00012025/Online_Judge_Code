#include<stdio.h>
#include<string.h>
bool black[50][50] ;
char s[1500] ;
int cnt,now ;

void solve(int x,int y,int len)
{
    if(s[now]=='f')
    {
        for(int i=x;i<x+len;i++) for(int j=y;j<y+len;j++)
        {
            if(!black[i][j]) cnt++ ;
            black[i][j]=1 ;
        }
        now++ ;
    }
    else if(s[now]=='e') now++ ;
    else if(s[now]=='p')
    {
        now++ ;
        solve(x,y+(len/2),len/2) ;
        solve(x,y,len/2) ;
        solve(x+(len/2),y,len/2) ;
        solve(x+(len/2),y+(len/2),len/2) ;
    }
}

main()
{
    int T;
    scanf("%d",&T) ;
    while(T--)
    {
        memset(black,0,sizeof(black)) ;
        cnt=0 ;
        for(int i=0;i<2;i++)
        {
            scanf("%s",s) ; now=0 ;
            solve(1,1,32) ;
        }
        printf("There are %d black pixels.\n",cnt) ;
    }
}
